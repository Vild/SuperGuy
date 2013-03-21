/* ============================================================================
 * Name        : dvarManager.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include "dvarManager.h"

void dvarManager::load(const char* file) {
	FILE * fp = fopen(file, "rt");
	if (!fp) {
		log::error("Couldn't load dvar file, reverting to standard dvars.");
		return;
	}



	fclose(fp);
}

dvarManager::dvarManager(const char * file) {
	this->dvarList = new boost::ptr_list<dvar>();
	this->file = file;

	load(file);
}

dvarManager::~dvarManager() {
	this->dvarList->clear();
	delete this->dvarList;
}

void dvarManager::registerDvar(dvar * dvar) {
	removeDvar(dvar->name);
	this->dvarList->push_back(dvar);
}

bool dvarManager::removeDvar(const char * name) {
	boost::ptr_list<dvar>::iterator it;
	for (it = this->dvarList->begin(); it != this->dvarList->end(); it++) {
		if (strcmp(name, it->name) == 0) {
			this->dvarList->erase(it);
			return true;
		}
	}
	return false;
}

dvar * dvarManager::GetDvar(const char * name) {
	boost::ptr_list<dvar>::iterator it;
	for (it = this->dvarList->begin(); it != this->dvarList->end(); it++) {
		if (strcmp(name, it->name) == 0)
			return it;
	}
	return NULL;
}
