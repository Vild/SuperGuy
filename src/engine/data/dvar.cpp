/* ============================================================================
 * Name        : dvar.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#include "dvar.h"
#include <cstdlib>
#include "../../log.h"
#include "../engine.h"

// The constructors for the dvar, does the same for each one, sets the name, descriptions, flags, value and default value.
dvar::dvar(std::string name, std::string desc, dvar_flag_t flags, int64_t Int) {
	this->name = name;
	this->desc = desc;
	this->flags = flags;
	this->value = Int;
	this->defValue = Int;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flags,
		std::string String) {
	this->name = name;
	this->desc = desc;
	this->flags = flags;
	this->value = String;
	this->defValue = String;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flags,
		double Double) {
	this->name = name;
	this->desc = desc;
	this->flags = flags;
	this->value = Double;
	this->defValue = Double;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flags, bool Bool) {
	this->name = name;
	this->desc = desc;
	this->flags = flags;
	this->value = Bool;
	this->defValue = Bool;
}

dvar::~dvar() {
	// Don't have to do a thing, C++ does this for us.
}

// Self explanatory
std::string dvar::getName() {
	return this->name;
}

std::string dvar::getDesc() {
	return this->desc;
}

dvar_flag_t dvar::getFlags() {
	return this->flags;
}

dvar_value_t dvar::getDefValue() {
	return this->defValue;
}

dvar_value_t dvar::getValue() {
	return this->value;
}

void dvar::setDesc(std::string desc) {
	this->desc = desc;
}

void dvar::setFlags(dvar_flag_t flag) {
	this->flags = flag;
}

void dvar::setDefValue(dvar_value_t defValue) {
	this->defValue = defValue;
}

dvar_flag_t dvar::setValue(dvar_value_t value) {
	bool cheat = false;
	dvar * cheats = engineInstance->dvarMgr->getDvar("cheats");
	if (cheats)
		cheat = boost::get<bool>(cheats->getValue());

	if (this->flags & DVAR_FLAG_READONLY) { // Checks if the dvar have the ReadOnly flag
		log::warning("Can't write to read only dvar '%s'", this->name.c_str());
		return DVAR_FLAG_READONLY;
	} else if (this->flags & DVAR_FLAG_WRITEPROTECTED) { // Checks if the dvar have the WriteProtected flag
		log::warning("Can't write to write protected dvar '%s'",
				this->name.c_str());
		return DVAR_FLAG_WRITEPROTECTED;
	} else if ((this->flags & DVAR_FLAG_CHEAT) && // Checks if the dvar have the Cheat flag and if so, checks the cheats dvar is true.
			cheat) {
		log::warning("Can't write to cheat protected dvar '%s'",
				this->name.c_str());
		return DVAR_FLAG_CHEAT;
	} else {
		this->value = value;
		return DVAR_FLAG_NONE;
	}
}
