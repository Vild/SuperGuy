/* ============================================================================
 * Name        : main.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

#include <iostream>
#include <SDL2/SDL.h>
#include "log.h"

int main(int argc, char ** argv) {
	log::open("log.txt");
	log::info("Intialized!");

	log::close();
	return 0;
}
