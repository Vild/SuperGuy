/* ============================================================================
 * Name        : dvar.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#ifndef DVAR_H_
#define DVAR_H_

#include <stdint.h>
#include <string>
#include <boost/variant.hpp>

typedef enum dvar_flag {
	DVAR_FLAG_NONE = 0x00,
	DVAR_FLAG_ARCHIVED = 0x01,
	DVAR_FLAG_WRITEPROTECTED = 0x02,
	DVAR_FLAG_CHEAT = 0x04,
	DVAR_FLAG_READONLY = 0x08,
	DVAR_FLAG_USERCREATED = 0x10
} dvar_flag_t;
inline dvar_flag_t operator|(dvar_flag_t a, dvar_flag_t b) {
	return static_cast<dvar_flag_t>(static_cast<int>(a) | static_cast<int>(b));
}

typedef boost::variant<int64_t, std::string, double, bool> dvar_value_t;

class dvar {
public:
	dvar(std::string name, std::string desc, dvar_flag_t flag, int64_t Int);
	dvar(std::string name, std::string desc, dvar_flag_t flag,
			std::string String);
	dvar(std::string name, std::string desc, dvar_flag_t flag, double Double);
	dvar(std::string name, std::string desc, dvar_flag_t flag, bool Bool);
	~dvar();

	std::string getName();
	std::string getDesc();
	dvar_flag_t getFlag();
	dvar_value_t getDefValue();
	dvar_value_t getValue();

	void setDesc(std::string desc);
	void setFlag(dvar_flag_t flag);
	void setDefValue(dvar_value_t defValue);
	void setValue(dvar_value_t value);
private:
	std::string name;
	std::string desc;
	dvar_flag_t flag;
	dvar_value_t defValue;
	dvar_value_t value;
};

#endif /* DVAR_H_ */
