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
	/*! \brief Creates a new dvar manager and loads the file \a file.
	 \param file The file which it will read and save the dvars too.
	 */
	dvarManager(std::string file);
	~dvarManager();

	/*! \brief Registers a new dvar or updates the description, flags and default value.
	 \param var The new dvar.
	 \return The registered dvar.
	 */
	dvar * registerDvar(dvar * var);
	/*! \brief Removes the dvar named \a name.
	 \param name The dvar name.
	 */
	void removeDvar(std::string name);
	/*! \brief Gets the dvar named \a name
	 \param name The dvar name.
	 \return The dvar or NULL if it couldn't find it.
	 */
	dvar * getDvar(std::string name);

private:
	std::map<std::string, dvar *> * dvarList;
	std::string file;

	void load(std::string file);
	void save(std::string file);
	dvar * registerDvar(dvar * var, bool load);
};

#endif /* DVARMANAGER_H_ */
