/*
 * log.h
 *
 *  Created on: Mar 13, 2013
 *      Author: ludkiller
 */

#ifndef LOG_H_
#define LOG_H_

class log {

public:
	static void info(const char * msg);
	static void error(const char * msg);
	static void warning(const char * msg);

	log();
	~log();

};

#endif /* LOG_H_ */
