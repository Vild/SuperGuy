/* ============================================================================
 * Name        : dvar.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#ifndef DVAR_H_
#define DVAR_H_

#include <stdint.h>

typedef enum dvar_flag {
	DVAR_FLAG_NONE = 0x00,
	DVAR_FLAG_SAVE = 0x01,
	DVAR_FLAG_READONLY = 0x02,
	DVAR_FLAG_CHEAT = 0x04
} dvar_flag_t;
typedef enum dvar_type {
	DVAR_TYPE_INT, DVAR_TYPE_STRING, DVAR_TYPE_DOUBLE
} dvar_type_t;
typedef union dvar_value {
	int64_t Int;
	char * String;
	double Double;
} dvar_value_t;

class dvar {
public:
	dvar(const char * name, const char * desc, dvar_flag_t flag,
			dvar_type_t type, dvar_value_t defValue);
	~dvar();

	const char * getName();
	const char * getDesc();
	dvar_flag_t getFlag();
	dvar_type_t getType();
	dvar_value_t getDefValue();
	dvar_value_t getValue();
private:
	const char * name;
	const char * desc;
	dvar_flag_t flag;
	dvar_type_t type;
	dvar_value_t defValue;
	dvar_value_t value;
};

#endif /* DVAR_H_ */
