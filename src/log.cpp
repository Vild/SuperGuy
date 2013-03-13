/*
 * log.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: ludkiller
 *      Author: WildN00b
 */
#include <stdio.h>
#include "log.h"
#include <iostream>

void log::loginfo(const char *msg) {
	std::cout << "[*] " << msg << std::endl;
}

void log::logerror(const char*msg) {
	std::cout << "[!] " << msg << std::endl;
}

log::log() {	
}

log::~log() {
}
