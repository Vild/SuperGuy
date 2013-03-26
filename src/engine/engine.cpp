/* ============================================================================
 * Name        : engine.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include <iostream>
#include "engine.h"
#include "../log.h"
#include <SDL2/SDL_image.h>

engine * engineInstance;

void engine::init_sdl() {
	int ret = 0;
	log::info("Initializing SDL2...");

	// Initialize SDL video.
	ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret) {
		log::error("Couldn't load SDL2! SDL_Init returned %i.", ret);
		throw new std::exception();
	}

	// Create a window
	window = SDL_CreateWindow("SuperGuy", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window) {
		log::error("Couldn't load SDL2! SDL_CreateWindow returned NULL");
		throw new std::exception();
	}

	// Create the renderer for the window.
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		log::error("Couldn't load SDL2! SDL_CreateRenderer returned NULL");
		throw new std::exception();
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		log::error("Couldn't init SDL2_image!");
		throw new std::exception();
	}

	log::info("Initialized SDL2 successfully!");
}

engine::engine() {
	log::info("Initalizing SuperGuy...");

	// Initialize SDL.
	init_sdl();

	// Create a new dvar manager and register the cheats dvar.
	dvarMgr = new dvarManager("dvar.cfg");
	cheats = dvarMgr->registerDvar(
			new dvar("cheats", "Enables cheats", DVAR_FLAG_ARCHIVED, true));
	log::info("Initialized SuperGuy successfully!");
}

engine::~engine() {
	delete dvarMgr;
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
	log::info("Shutting down SuperGuy, Bye!");
}
