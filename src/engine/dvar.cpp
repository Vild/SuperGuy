/* ============================================================================
 * Name        : dvar.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#include "dvar.h"
#include <cstdlib>
#include "../log.h"

dvar::dvar(std::string name, std::string desc, dvar_flag_t flag, int64_t Int) {
	this->name = name;
	this->desc = desc;
	this->flag = flag;
	this->value = Int;
	this->defValue = Int;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flag,
		std::string String) {
	this->name = name;
	this->desc = desc;
	this->flag = flag;
	this->value = String;
	this->defValue = String;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flag,
		double Double) {
	this->name = name;
	this->desc = desc;
	this->flag = flag;
	this->value = Double;
	this->defValue = Double;
}

dvar::dvar(std::string name, std::string desc, dvar_flag_t flag, bool Bool) {
	this->name = name;
	this->desc = desc;
	this->flag = flag;
	this->value = Bool;
	this->defValue = Bool;
}

dvar::~dvar() {
}

std::string dvar::getName() {
	return this->name;
}

std::string dvar::getDesc() {
	return this->desc;
}

dvar_flag_t dvar::getFlag() {
	return this->flag;
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

void dvar::setFlag(dvar_flag_t flag) {
	this->flag = flag;
}

void dvar::setDefValue(dvar_value_t defValue) {
	this->defValue = defValue;
}

void dvar::setValue(dvar_value_t value) {
	if (this->flag & DVAR_FLAG_READONLY)
		log::warning("Can't write to read only dvar '%s'", this->name.c_str());
	else if (this->flag & DVAR_FLAG_WRITEPROTECTED)
		log::warning("Can't write to write protected dvar '%s'",
				this->name.c_str());
	else
		this->value = value;
}
