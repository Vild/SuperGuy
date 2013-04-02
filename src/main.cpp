/* ============================================================================
 * Name        : main.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

#include <SDL2/SDL.h>
#include "Log.h"
#include "Engine/Engine.h"

int main(int argc, char ** argv) {
	Log::Open("log.txt");

	try {
		EngineInstance = new Engine();

		SDL_Delay(5 * 1000);

		delete EngineInstance;
	} catch (std::exception * e) {
		if (EngineInstance) // Checks if eng isn't NULL
			delete EngineInstance;
		Log::Error("Engine crashed!");
	}

	Log::Close();
	return 0;
}
