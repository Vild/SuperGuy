/* ============================================================================
 * Name        : dvar.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include "dvar.h"
#include <cstdlib>

dvar::dvar(const char * name, const char * desc, dvar_flag_t flag,
		dvar_type_t type, dvar_value_t defValue) {
	this->name = name;
	this->desc = desc;
	this->flag = flag;
	this->type = type;
	this->defValue = defValue;
	this->value = defValue;
}

dvar::~dvar() {
	if (this->type == DVAR_TYPE_STRING) {
		if (this->defValue.String)
			free(this->defValue.String);
		if (this->value.String)
			free(this->value.String);
	}
}

const char * dvar::getName() {
	return this->name;
}

const char * dvar::getDesc() {
	return this->desc;
}

dvar_flag_t dvar::getFlag() {
	return this->flag;
}

dvar_type_t dvar::getType() {
	return this->type;
}

dvar_value_t dvar::getDefValue() {
	return this->defValue;
}

dvar_value_t dvar::getValue() {
	return this->value;
}
