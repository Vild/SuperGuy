/* ============================================================================
 * Name        : main.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

#include <SDL2/SDL.h>
#include "log.h"
#include "engine/engine.h"

int main(int argc, char ** argv) {
	log::open("log.txt");

	try {
		engineInstance = new engine();

		SDL_Delay(5 * 1000);

		delete engineInstance;
	} catch (std::exception * e) {
		if (engineInstance) // Checks if eng isn't NULL
			delete engineInstance;
		log::error("Engine crashed!");
	}

	log::close();
	return 0;
}
