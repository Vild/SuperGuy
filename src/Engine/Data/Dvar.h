/* ============================================================================
 * Name        : Dvar.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Class for the dvars
 * ============================================================================ */

#ifndef DVAR_H_
#define DVAR_H_

#include <stdint.h>
#include <string>
#include <boost/variant.hpp>

typedef enum Dvar_flag {
	DVAR_FLAG_NONE = 0x00,
	DVAR_FLAG_ARCHIVED = 0x01,
	DVAR_FLAG_WRITEPROTECTED = 0x02,
	DVAR_FLAG_CHEAT = 0x04,
	DVAR_FLAG_READONLY = 0x08,
	DVAR_FLAG_USERCREATED = 0x10
} Dvar_flag_t;

inline Dvar_flag_t operator|(Dvar_flag_t a, Dvar_flag_t b) {
	return static_cast<Dvar_flag_t>(static_cast<int>(a) | static_cast<int>(b));
}

typedef boost::variant<int64_t, std::string, double, bool> Dvar_value_t;

/*! \brief Class for the dvars
 */
class Dvar {
public:
	/*! \brief Makes a new dvar with the type of a integer.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Int The default value for the dvar.
	 */
	Dvar(std::string name, std::string desc, Dvar_flag_t flags, int64_t Int);
	/*! \brief Makes a new dvar with the type of a string.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param String The default value for the dvar.
	 */
	Dvar(std::string name, std::string desc, Dvar_flag_t flags,
			std::string String);
	/*! \brief Makes a new dvar with the type of a double.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Double The default value for the dvar.
	 */
	Dvar(std::string name, std::string desc, Dvar_flag_t flags, double Double);
	/*! \brief Makes a new dvar with the type of a boolean.
	 \param name The name of the dvar.
	 \param desc The description of the dvar.
	 \param flags The flags for the dvar.
	 \param Bool The default value for the dvar.
	 */
	Dvar(std::string name, std::string desc, Dvar_flag_t flags, bool Bool);
	~Dvar();

	/*! \brief Returns the name of the dvar.
	 \return The name of the dvar.
	 */
	std::string GetName();
	/*! \brief Returns the description of the dvar.
	 \return The description of the dvar.
	 */
	std::string GetDesc();
	/*! \brief Returns the flags of the dvar.
	 \return The flags of the dvar.
	 */
	Dvar_flag_t GetFlags();
	/*! \brief Returns the default value of the dvar.
	 \return The default value of the dvar.
	 */
	Dvar_value_t GetDefValue();
	/*! \brief Returns the value of the dvar.
	 \return The value of the dvar.
	 */
	Dvar_value_t GetValue();

	/*! \brief Sets the description of the dvar.
	 \param desc The description.
	 */
	void SetDesc(std::string desc);
	/*! \brief Sets the flags of the dvar.
	 \param flag The flags.
	 */
	void SetFlags(Dvar_flag_t flag);
	/*! \brief Sets the default value of the dvar.
	 \param defValue The default value.
	 */
	void SetDefValue(Dvar_value_t defValue);
	/*! \brief Sets the value of the dvar and returns DVAR_FLAG_NONE if it succeeded else it return the flag that stopped it.
	 \param value The value.
	 \return The flag that stopped it or DVAR_FLAG_NONE if it succeeded.
	 */
	Dvar_flag_t SetValue(Dvar_value_t value);
private:
	std::string Name;
	std::string Desc;
	Dvar_flag_t Flags;
	Dvar_value_t DefValue;
	Dvar_value_t Value;
};

#endif /* DVAR_H_ */
