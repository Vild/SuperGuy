/*
 * log.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: ludkiller
 *      Author: WildN00b
 */
#include <stdio.h>
#include "log.h"
#include <cstdio>
#include <stdarg.h>

void log::info(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	puts("[*] ");
	vprintf(msg, va);
	puts("\n");
	va_end(va);
}

void log::error(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	puts("[!] ");
	vprintf(msg, va);
	puts("\n");
	va_end(va);
}

void log::warning(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	puts("[#] ");
	vprintf(msg, va);
	puts("\n");
	va_end(va);
}

log::log() {
}

log::~log() {
}
