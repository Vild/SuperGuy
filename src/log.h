/*
 * log.h
 *
 *  Created on: Mar 13, 2013
 *      Author: ludkiller
 */

#ifndef LOG_H_
#define LOG_H_

#define DEBUG = 1;
class log {

public:
	void loginfo(const char *);
	void logerror(const char *);
	log();
	~log();

};

#endif /* LOG_H_ */
