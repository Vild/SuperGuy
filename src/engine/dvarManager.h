/* ============================================================================
 * Name        : dvarManager.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef DVARMANAGER_H_
#define DVARMANAGER_H_

#include "dvar.h"
#include <boost/ptr_container/ptr_list.hpp>

class dvarManager {
public:
	dvarManager(const char * file);
	~dvarManager();

	void registerDvar(dvar * dvar);
	bool removeDvar(const char * name);
	dvar * GetDvar(const char * name);

private:
	boost::ptr_list<dvar> * dvarList;
	const char * file;

	void load(const char* file);
};

#endif /* DVARMANAGER_H_ */
