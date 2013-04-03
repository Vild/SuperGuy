/* ============================================================================
 * Name        : Log.h
 * Author(s)   : ludkiller, Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Logging class
 * ============================================================================ */

#ifndef LOG_H_
#define LOG_H_

/*! \brief Logging class
 */
class Log {

public:
	Log();
	~Log();

	/*! \brief Opens \a file for writing the a log file.
	 \param file The file to be written too.
	 \return If it succeeded.
	 */
	static bool Open(const char * file);
	/*! \brief Closes the log file.
	 */
	static void Close();

	/*! \brief Writes a info message to the log file and the console.
	 \param msg The message.
	 */
	static void Info(const char * msg, ...);
	/*! \brief Writes a error message to the log file and the console.
	 \param msg The message.
	 */
	static void Error(const char * msg, ...);
	/*! \brief Writes a warning message to the log file and the console.
	 \param msg The message.
	 */
	static void Warning(const char * msg, ...);
};

#endif /* LOG_H_ */
