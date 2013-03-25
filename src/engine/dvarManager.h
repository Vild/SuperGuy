/* ============================================================================
 * Name        : dvarManager.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : A manager for dvars
 * ============================================================================ */

#ifndef DVARMANAGER_H_
#define DVARMANAGER_H_

#include "dvar.h"
#include <map>
#include <string>

class dvarManager {
public:
	dvarManager(std::string file);
	~dvarManager();

	dvar * registerDvar(dvar * var);
	void removeDvar(std::string name);
	dvar * getDvar(std::string name);

private:
	std::map<std::string, dvar *> * dvarList;
	std::string file;

	void load(std::string file);
	void save(std::string file);
	dvar * registerDvar(dvar * var, bool load);
};

#endif /* DVARMANAGER_H_ */
