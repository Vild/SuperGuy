/* ============================================================================
 * Name        : log.cpp
 * Author(s)   : ludkiller, Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : Logging class
 * ============================================================================ */

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
