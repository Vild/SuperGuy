/* ============================================================================
 * Name        : DvarManager.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : A manager for dvars
 * ============================================================================ */

#include "DvarManager.h"
#include "../../Log.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

// Functions for splitting a string with the delimiter into a vector.
static std::vector<std::string> &Split(const std::string &s, char delim,
		std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

static std::vector<std::string> Split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return Split(s, delim, elems);
}

/* Format for file
 * TYPE NAME VALUE
 * like
 * bool cheats 0
 * string name WildN00b
 */

void DvarManager::Load(std::string file) {
	unsigned int i;
	char line[512];
	std::filebuf fb;
	std::istream * in;
	std::vector<std::string> splitLine;
	std::string stringTmp;

	// Opens the file for reading
	if (!fb.open(file.c_str(), std::ios::in)) {
		Log::Error("Couldn't load dvar file, reverting to standard dvars.");
		return;
	}
	in = new std::istream(&fb);

	while (in->good()) { // While there are data left.
		// Read a line.
		in->getline(line, 512);
		if (!line[0])
			break;
		// Split up the line.
		splitLine = Split(std::string(line), ' ');

		/* Start to parse the first section which is what type the data is.
		 * Then create and register the dvar it found if the type is valid.
		 */
		if (splitLine.at(0) == "int")
			RegisterDvar(
					new Dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							(int64_t)atoll(splitLine.at(2).c_str())), true); // atol because int type is a int64_t
		else if (splitLine.at(0) == "string") {
			// Loop through all the left entries in the vector which will be the string.
			for (i = 2; i < splitLine.size(); i++)
				stringTmp += splitLine.at(i); // Append the parts to string which will be used for making the dvar.
			RegisterDvar(
					new Dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							stringTmp), true);
		} else if (splitLine.at(0) == "double")
			RegisterDvar(
					new Dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atof(splitLine.at(2).c_str())), true); // atof because is a double
		else if (splitLine.at(0) == "bool")
			RegisterDvar(
					new Dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atoi(splitLine.at(2).c_str()) != 0), true); // atoi because it saves the booleans as 1 or 0
		else if (splitLine.at(0).c_str()[0] != '#') // # can be used as comments.
			Log::Warning("[DvarManager] Unknown type %s", // Just skip unknowed types.
					splitLine.at(0).c_str());
	}

	// Don't forget to close the file. ;)
	fb.close();
	delete in;
}

void DvarManager::Save(std::string file) {
	std::filebuf fb;
	Dvar * var;

	// Opens the file for writing.
	if (!fb.open(file.c_str(), std::ios::out)) {
		Log::Error("Couldn't open dvar file for saving!");
		return;
	}
	std::ostream out(&fb);

	// For each dvar in the registed dvar list.
	for (std::map<std::string, Dvar *>::iterator it = this->DvarList->begin();
			it != this->DvarList->end(); ++it) {
		var = it->second;

		// If the dvar havn't got the Archived flag, just skip it.
		if (!(var->GetFlags() & DVAR_FLAG_ARCHIVED))
			continue;
		try {
			// Check what type the dvar is and write it out.
			if (var->GetValue().type() == typeid(int64_t))
				out << "int" << " ";
			else if (var->GetValue().type() == typeid(std::string))
				out << "string" << " ";
			else if (var->GetValue().type() == typeid(double))
				out << "double" << " ";
			else if (var->GetValue().type() == typeid(bool))
				out << "bool" << " ";
			else
				continue; // Skip unknown types.
			// Write out the name and the value.
			out << var->GetName() << " " << var->GetValue() << " " << "\n";
		} catch (std::exception & e) {
			Log::Error(e.what()); // Print the exception to the log.
		}
	}

	// Don't forget to close the file. ;)
	fb.close();
}

DvarManager::DvarManager(std::string file) {
	this->DvarList = new std::map<std::string, Dvar *>();
	this->File = file;

	// Load the dvars from the file.
	try {
		Load(file);
	} catch (std::exception & e) {
		Log::Warning("Failed to load dvars!");
	}
}

DvarManager::~DvarManager() {
	// Save the dvars to the file.
	try {
		Save(this->File);
	} catch (std::exception & e) {
		Log::Warning("Failed to save dvars!");
	}

	// Free all the dvars
	for (std::map<std::string, Dvar *>::iterator it = this->DvarList->begin();
			it != this->DvarList->end(); ++it) {
		delete it->second;
	}

	// Clear and free the list.
	this->DvarList->clear();
	delete this->DvarList;
}

Dvar * DvarManager::RegisterDvar(Dvar * var) {
	return RegisterDvar(var, false);
}

Dvar * DvarManager::RegisterDvar(Dvar * var, bool load) {
	// Get if theirs already a dvar named the same as var.
	Dvar * stored = GetDvar(var->GetName());

	if (load || !stored) { // If there arn't any dvar named the same as var or it's in the progress or loading the dvars.
		RemoveDvar(var->GetName()); // Just to be safe. ;)
		this->DvarList->insert(
				std::pair<std::string, Dvar *>(var->GetName(), var)); // Add the dvar to the list.
		return var;
	} else {
		// If the dvar already exist, Just update the description, flags and default value.
		stored->SetDesc(var->GetDesc());
		stored->SetFlags(var->GetFlags());
		stored->SetDefValue(var->GetDefValue());
		delete var; // Delete var because we don't need it anymore.
		return stored;
	}
}

void DvarManager::RemoveDvar(std::string name) {
	try { // I use try here because if the dvar doesn't exist, it will cause an exception.
		  // Free the dvar and remove it form the list.
		delete this->DvarList->at(name);
		this->DvarList->erase(name);
	} catch (std::exception & e) {
	}
}

Dvar * DvarManager::GetDvar(std::string name) {
	try { // If it can't find the dvar it will throw an exception.
		  // Return the dvar.
		return this->DvarList->at(name);
	} catch (std::exception & e) {
		// If it couldn't find it return NULL.
		return NULL;
	}
}
