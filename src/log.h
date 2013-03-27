/* ============================================================================
 * Name        : log.h
 * Author(s)   : ludkiller
 * Copyright   : FreeBSD
 * Description : Logging class
 * ============================================================================ */

#ifndef LOG_H_
#define LOG_H_

#include <string>

class log {

public:
	log();
	~log();

	/*! \brief Opens \a file for writing the a log file.
	 \param file The file to be written too.
	 \return If it succeeded.
	 */
	static bool open(const char * file);
	/*! \brief Closes the log file.
	 */
	static void close();

	/*! \brief Writes a info message to the log file and the console.
	 \param msg The message.
	 */
	static void info(const char * msg, ...);
	/*! \brief Writes a error message to the log file and the console.
	 \param msg The message.
	 */
	static void error(const char * msg, ...);
	/*! \brief Writes a warning message to the log file and the console.
	 \param msg The message.
	 */
	static void warning(const char * msg, ...);
};

#endif /* LOG_H_ */
