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

std::vector<std::string> &split(const std::string &s, char delim,
		std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return split(s, delim, elems);
}

/*
 * Format for file
 * TYPE NAME VALUE
 * like
 * bool cheats false
 * string name WildN00b
 */

void dvarManager::load(std::string file) {
	std::filebuf fb;
	std::istream * in;
	std::string line;
	char tmp[512];
	std::vector<std::string> s;
	std::string stmp;
	unsigned int i;
	if (!fb.open(file.c_str(), std::ios::in)) {
		log::error("Couldn't load dvar file, reverting to standard dvars.");
		return;
	}
	in = new std::istream(&fb);
	while (in) {
		in->getline(tmp, 512);
		if (!tmp[0])
			break;
		line = tmp;
		s = split(line, ' ');
		log::info("'%s' '%s' '%s'", s.at(0).c_str(), s.at(1).c_str(),
				s.at(2).c_str());
		if (s.at(0) == "int")
			registerDvar(
					new dvar(s.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atol(s.at(2).c_str())), true);
		else if (s.at(0) == "string") {
			for (i = 2; i < s.size(); i++)
				stmp += s.at(i);
			registerDvar(
					new dvar(s.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							stmp), true);
		} else if (s.at(0) == "double")
			registerDvar(
					new dvar(s.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atof(s.at(2).c_str())), true);
		else if (s.at(0) == "bool")
			registerDvar(
					new dvar(s.at(1).c_str(), "",
							DVAR_FLAG_USERCREATED | DVAR_FLAG_ARCHIVED,
							atoi(s.at(2).c_str()) != 0), true);
		else if (s.at(0).c_str()[0] != '#')
			log::warning("[DvarManager] Unknown type %s", s.at(0).c_str());
	}
	fb.close();
	delete in;
}

void dvarManager::save(std::string file) {
	std::filebuf fb;
	dvar * var;
	if (!fb.open(file.c_str(), std::ios::out)) {
		log::error("Couldn't open dvar file for saving!");
		return;
	}
	std::ostream out(&fb);

	for (std::map<std::string, dvar *>::iterator it = this->dvarList->begin();
			it != this->dvarList->end(); ++it) {
		var = it->second;
		if (!(var->getFlag() & DVAR_FLAG_ARCHIVED))
			continue;
		try {
			log::info("name: %s, type: %s, string:%s", var->getName().c_str(),
					var->getValue().type().name(), typeid(std::string).name());
			if (var->getValue().type() == typeid(int64_t))
				out << "int" << " ";
			else if (var->getValue().type() == typeid(std::string))
				out << "string" << " ";
			else if (var->getValue().type() == typeid(double))
				out << "double" << " ";
			else if (var->getValue().type() == typeid(bool))
				out << "bool" << " ";
			else
				continue;
			out << var->getName() << " " << var->getValue() << " " << "\n";
		} catch (std::exception & e) {
			log::error(e.what());
		}
	}

	fb.close();
}

dvarManager::dvarManager(std::string file) {
	this->dvarList = new std::map<std::string, dvar *>();
	this->file = file;
	try {
		load(file);
	} catch (std::exception & e) {
		log::warning("Failed to load dvars!");
	}
}

dvarManager::~dvarManager() {
	try {
		save(this->file);
	} catch (std::exception & e) {
		log::warning("Failed to save dvars!");
	}

	for (std::map<std::string, dvar *>::iterator it = this->dvarList->begin();
			it != this->dvarList->end(); ++it) {
		delete it->second;
	}
	this->dvarList->clear();
	delete this->dvarList;
}

dvar * dvarManager::registerDvar(dvar * var) {
	return registerDvar(var, false);
}

dvar * dvarManager::registerDvar(dvar * var, bool load) {
	dvar * stored = getDvar(var->getName());
	if (load || !stored) {
		removeDvar(var->getName());
		this->dvarList->insert(
				std::pair<std::string, dvar *>(var->getName(), var));
		return var;
	} else {
		stored->setDesc(var->getDesc());
		stored->setFlag(var->getFlag());
		stored->setDefValue(var->getDefValue());
		delete var;
		return stored;
	}
}

void dvarManager::removeDvar(std::string name) {
	try {
		delete this->dvarList->at(name);
		this->dvarList->erase(name);
	} catch (std::exception & e) {
	}
}

dvar * dvarManager::getDvar(std::string name) {
	try {
		return this->dvarList->at(name);
	} catch (std::exception & e) {
		return NULL;
	}
}
