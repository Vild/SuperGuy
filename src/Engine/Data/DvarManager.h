/* ============================================================================
 * Name        : DvarManager.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : A manager for the dvars
 * ============================================================================ */

#ifndef DVARMANAGER_H_
#define DVARMANAGER_H_

#include "Dvar.h"
#include <map>
#include <string>

/*! \brief A manager for the dvars
 */
class DvarManager {
public:
	/*! \brief Creates a new dvar manager and loads the file \a file.
	 \param file The file which it will read and save the dvars too.
	 */
	DvarManager(std::string file);
	~DvarManager();

	/*! \brief Registers a new dvar or updates the description, flags and default value.
	 \param var The new dvar.
	 \return The registered dvar.
	 */
	Dvar * RegisterDvar(Dvar * var);
	/*! \brief Removes the dvar named \a name.
	 \param name The dvar name.
	 */
	void RemoveDvar(std::string name);
	/*! \brief Gets the dvar named \a name
	 \param name The dvar name.
	 \return The dvar or NULL if it couldn't find it.
	 */
	Dvar * GetDvar(std::string name);

private:
	std::map<std::string, Dvar *> * DvarList;
	std::string File;

	void Load(std::string file);
	void Save(std::string file);
	Dvar * RegisterDvar(Dvar * var, bool load);
};

#endif /* DVARMANAGER_H_ */
