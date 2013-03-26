/* ============================================================================
 * Name        : dvarManager.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : A manager for dvars
 * ============================================================================ */

#include "dvarManager.h"
#include "../log.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

// Functions for splitting a string with the delimiter into a vector.
static std::vector<std::string> &split(const std::string &s, char delim,
		std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

static std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return split(s, delim, elems);
}

/* Format for file
 * TYPE NAME VALUE
 * like
 * bool cheats 0
 * string name WildN00b
 */

void dvarManager::load(std::string file) {
	unsigned int i;
	char line[512];
	std::filebuf fb;
	std::istream * in;
	std::vector<std::string> splitLine;
	std::string stringTmp;

	// Opens the file for reading
	if (!fb.open(file.c_str(), std::ios::in)) {
		log::error("Couldn't load dvar file, reverting to standard dvars.");
		return;
	}
	in = new std::istream(&fb);

	while (in->good()) { // While there are data left.
		// Read a line.
		in->getline(line, 512);
		if (!line[0])
			break;
		// Split up the line.
		splitLine = split(std::string(line), ' ');

		/* Start to parse the first section which is what type the data is.
		 * Then create and register the dvar it found if the type is valid.
		 */
		if (splitLine.at(0) == "int")
			registerDvar(
					new dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atol(splitLine.at(2).c_str())), true); // atol because int type is a int64_t
		else if (splitLine.at(0) == "string") {
			// Loop through all the left entries in the vector which will be the string.
			for (i = 2; i < splitLine.size(); i++)
				stringTmp += splitLine.at(i); // Append the parts to string which will be used for making the dvar.
			registerDvar(
					new dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							stringTmp), true);
		} else if (splitLine.at(0) == "double")
			registerDvar(
					new dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atof(splitLine.at(2).c_str())), true); // atof because is a double
		else if (splitLine.at(0) == "bool")
			registerDvar(
					new dvar(splitLine.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atoi(splitLine.at(2).c_str()) != 0), true); // atoi because it saves the booleans as 1 or 0
		else if (splitLine.at(0).c_str()[0] != '#') // # can be used as comments.
			log::warning("[DvarManager] Unknown type %s", // Just skip unknowed types.
					splitLine.at(0).c_str());
	}

	// Don't forget to close the file. ;)
	fb.close();
	delete in;
}

void dvarManager::save(std::string file) {
	std::filebuf fb;
	dvar * var;

	// Opens the file for writing.
	if (!fb.open(file.c_str(), std::ios::out)) {
		log::error("Couldn't open dvar file for saving!");
		return;
	}
	std::ostream out(&fb);

	// For each dvar in the registed dvar list.
	for (std::map<std::string, dvar *>::iterator it = this->dvarList->begin();
			it != this->dvarList->end(); ++it) {
		var = it->second;

		// If the dvar havn't got the Archived flag, just skip it.
		if (!(var->getFlags() & DVAR_FLAG_ARCHIVED))
			continue;
		try {
			// Check what type the dvar is and write it out.
			if (var->getValue().type() == typeid(int64_t))
				out << "int" << " ";
			else if (var->getValue().type() == typeid(std::string))
				out << "string" << " ";
			else if (var->getValue().type() == typeid(double))
				out << "double" << " ";
			else if (var->getValue().type() == typeid(bool))
				out << "bool" << " ";
			else
				continue; // Skip unknown types.
			// Write out the name and the value.
			out << var->getName() << " " << var->getValue() << " " << "\n";
		} catch (std::exception & e) {
			log::error(e.what()); // Print the exception to the log.
		}
	}

	// Don't forget to close the file. ;)
	fb.close();
}

dvarManager::dvarManager(std::string file) {
	this->dvarList = new std::map<std::string, dvar *>();
	this->file = file;

	// Load the dvars from the file.
	try {
		load(file);
	} catch (std::exception & e) {
		log::warning("Failed to load dvars!");
	}
}

dvarManager::~dvarManager() {
	// Save the dvars to the file.
	try {
		save(this->file);
	} catch (std::exception & e) {
		log::warning("Failed to save dvars!");
	}

	// Free all the dvars
	for (std::map<std::string, dvar *>::iterator it = this->dvarList->begin();
			it != this->dvarList->end(); ++it) {
		delete it->second;
	}

	// Clear and free the list.
	this->dvarList->clear();
	delete this->dvarList;
}

dvar * dvarManager::registerDvar(dvar * var) {
	return registerDvar(var, false);
}

dvar * dvarManager::registerDvar(dvar * var, bool load) {
	// Get if theirs already a dvar named the same as var.
	dvar * stored = getDvar(var->getName());

	if (load || !stored) { // If there arn't any dvar named the same as var or it's in the progress or loading the dvars.
		removeDvar(var->getName()); // Just to be safe. ;)
		this->dvarList->insert(
				std::pair<std::string, dvar *>(var->getName(), var)); // Add the dvar to the list.
		return var;
	} else {
		// If the dvar already exist, Just update the description, flags and default value.
		stored->setDesc(var->getDesc());
		stored->setFlags(var->getFlags());
		stored->setDefValue(var->getDefValue());
		delete var; // Delete var because we don't need it anymore.
		return stored;
	}
}

void dvarManager::removeDvar(std::string name) {
	try { // I use try here because if the dvar doesn't exist, it will cause an exception.
		  // Free the dvar and remove it form the list.
		delete this->dvarList->at(name);
		this->dvarList->erase(name);
	} catch (std::exception & e) {
	}
}

dvar * dvarManager::getDvar(std::string name) {
	try { // If it can't find the dvar it will throw an exception.
		  // Return the dvar.
		return this->dvarList->at(name);
	} catch (std::exception & e) {
		// If it couldn't find it return NULL.
		return NULL;
	}
}
