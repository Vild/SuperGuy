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
	int ret = 0;
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;
	log::open("log.txt");
	log::info("Initalizing SuperGuy...");
	log::info("Initalizing SDL2...");
	ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret) {
		log::error("Couldn't load SDL2! SDL_Init returned %i.", ret);
		goto cleanup;
	}
	window = SDL_CreateWindow("SuperGuy", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window) {
		log::error("Couldn't load SDL2! SDL_CreateWindow returned NULL");
		goto cleanup_sdl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		log::error("Couldn't load SDL2! SDL_CreateRenderer returned NULL");
		goto cleanup_window;
	}
	log::info("Initialized SDL2 successfully!");
	log::info("Initialized SuperGuy successfully!");

	SDL_Delay(5 * 1000);

	SDL_DestroyRenderer(renderer);
	cleanup_window: SDL_DestroyWindow(window);
	cleanup_sdl: SDL_Quit();
	cleanup: log::info("Shutting down SuperGuy, Bye!");
	log::close();
	return 0;
}
