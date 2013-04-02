/* ============================================================================
 * Name        : Dvar.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#include "Dvar.h"
#include "../../Log.h"
#include "../Engine.h"

// The constructors for the dvar, does the same for each one, sets the name, descriptions, flags, value and default value.
Dvar::Dvar(std::string name, std::string desc, Dvar_flag_t flags, int64_t Int) {
	this->Name = name;
	this->Desc = desc;
	this->Flags = flags;
	this->Value = Int;
	this->DefValue = Int;
}

Dvar::Dvar(std::string name, std::string desc, Dvar_flag_t flags,
		std::string String) {
	this->Name = name;
	this->Desc = desc;
	this->Flags = flags;
	this->Value = String;
	this->DefValue = String;
}

Dvar::Dvar(std::string name, std::string desc, Dvar_flag_t flags,
		double Double) {
	this->Name = name;
	this->Desc = desc;
	this->Flags = flags;
	this->Value = Double;
	this->DefValue = Double;
}

Dvar::Dvar(std::string name, std::string desc, Dvar_flag_t flags, bool Bool) {
	this->Name = name;
	this->Desc = desc;
	this->Flags = flags;
	this->Value = Bool;
	this->DefValue = Bool;
}

Dvar::~Dvar() {
	// Don't have to do a thing, C++ does this for us.
}

// Self explanatory
std::string Dvar::GetName() {
	return this->Name;
}

std::string Dvar::GetDesc() {
	return this->Desc;
}

Dvar_flag_t Dvar::GetFlags() {
	return this->Flags;
}

Dvar_value_t Dvar::GetDefValue() {
	return this->DefValue;
}

Dvar_value_t Dvar::GetValue() {
	return this->Value;
}

void Dvar::SetDesc(std::string desc) {
	this->Desc = desc;
}

void Dvar::SetFlags(Dvar_flag_t flag) {
	this->Flags = flag;
}

void Dvar::SetDefValue(Dvar_value_t defValue) {
	this->DefValue = defValue;
}

Dvar_flag_t Dvar::SetValue(Dvar_value_t value) {
	bool cheat = false;
	Dvar * cheats = EngineInstance->DvarMgr->GetDvar("cheats");
	if (cheats)
		cheat = boost::get<bool>(cheats->GetValue());

	if (this->Flags & DVAR_FLAG_READONLY) { // Checks if the dvar have the ReadOnly flag
		Log::Warning("Can't write to read only dvar '%s'", this->Name.c_str());
		return DVAR_FLAG_READONLY;
	} else if (this->Flags & DVAR_FLAG_WRITEPROTECTED) { // Checks if the dvar have the WriteProtected flag
		Log::Warning("Can't write to write protected dvar '%s'",
				this->Name.c_str());
		return DVAR_FLAG_WRITEPROTECTED;
	} else if ((this->Flags & DVAR_FLAG_CHEAT) && // Checks if the dvar have the Cheat flag and if so, checks the cheats dvar is true.
			cheat) {
		Log::Warning("Can't write to cheat protected dvar '%s'",
				this->Name.c_str());
		return DVAR_FLAG_CHEAT;
	} else {
		this->Value = value;
		return DVAR_FLAG_NONE;
	}
}
