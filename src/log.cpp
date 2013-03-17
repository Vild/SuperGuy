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
#include <ctime>

static char buf[80];

static char * getTime() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buf, 80, "%Ex - %EX", timeinfo);
	return buf;
}

void log::info(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	printf("%-18s [*] ", getTime());
	vprintf(msg, va);
	printf("\n");
	va_end(va);
}

void log::error(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	printf("%-18s [!] ", getTime());
	vprintf(msg, va);
	printf("\n");
	va_end(va);
}

void log::warning(const char * msg, ...) {
	va_list va;
	va_start(va, msg);
	printf("%-18s [#] ", getTime());
	vprintf(msg, va);
	printf("\n");
	va_end(va);
}

log::log() {
}

log::~log() {
}
