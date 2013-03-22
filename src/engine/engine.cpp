/* ============================================================================
 * Name        : engine.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include <iostream>
#include "engine.h"
#include "../log.h"

void engine::init_sdl() {
	int ret = 0;
	log::info("Initializing SDL2...");
	ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret) {
		log::error("Couldn't load SDL2! SDL_Init returned %i.", ret);
		throw new std::exception();
	}
	window = SDL_CreateWindow("SuperGuy", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window) {
		log::error("Couldn't load SDL2! SDL_CreateWindow returned NULL");
		throw new std::exception();
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		log::error("Couldn't load SDL2! SDL_CreateRenderer returned NULL");
		throw new std::exception();
	}
	log::info("Initialized SDL2 successfully!");
}

engine::engine() {
	log::info("Initalizing SuperGuy...");
	init_sdl();
	log::info("Initialized SuperGuy successfully!");
}

engine::~engine() {
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
	log::info("Shutting down SuperGuy, Bye!");
}
