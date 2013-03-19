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
#include <cstring>

static char buf[80];
FILE * fp = NULL;

static char * getTime() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buf, 80, "%Ex - %EX", timeinfo);
	return buf;
}

log::log() {
}

log::~log() {
}

bool log::open(const char * file) {
	fp = fopen(file, "at");
	if (!fp)
		fp = fopen(file, "wt");
	if (!fp) {
		error("Failed to open '%s', disregards saving log file.", file);
		return false;
	}

	return true;
}

void log::close() {
	if (fp) {
		fclose(fp);
		fp = NULL;
	}
}

void log::info(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	va_start(va, msg);
	sprintf(buf, "%-18s [*] ", getTime());
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}

void log::error(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	va_start(va, msg);
	sprintf(buf, "%-18s [!] ", getTime());
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}

void log::warning(const char * msg, ...) {
	char buf[512] = "\0";
	va_list va;

	va_start(va, msg);
	sprintf(buf, "%-18s [#] ", getTime());
	vsprintf(buf + strlen(buf), msg, va);
	sprintf(buf + strlen(buf), "\n");
	va_end(va);

	printf(buf);
	if (fp) {
		fprintf(fp, buf);
		fflush(fp);
	}
}
