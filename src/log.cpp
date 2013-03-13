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

void log::info(const char * msg) {
	std::cout << "[*] " << msg << std::endl;
}

void log::error(const char * msg) {
	std::cout << "[!] " << msg << std::endl;
}

void log::warning(const char * msg) {
	std::cout << "[#] " << msg << std::endl;
}

log::log() {
}

log::~log() {
}
