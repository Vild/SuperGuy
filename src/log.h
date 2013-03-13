/* ============================================================================
 * Name        : log.h
 * Author(s)   : ludkiller
 * Copyright   : FreeBSD
 * Description : Logging class
 * ============================================================================ */

#ifndef LOG_H_
#define LOG_H_

class log {

public:
	static void info(const char * msg, ...);
	static void error(const char * msg, ...);
	static void warning(const char * msg, ...);

	log();
	~log();

};

#endif /* LOG_H_ */
