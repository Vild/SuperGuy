/* ============================================================================
 * Name        : Engine.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : Game engine class
 * ============================================================================ */

#include <iostream>
#include "Engine.h"
#include "../Log.h"
#include <SDL2/SDL_image.h>

Engine * EngineInstance;

void Engine::InitSDL() {
	int ret = 0;
	Log::Info("Initializing SDL2...");

	// Initialize SDL video.
	ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret) {
		Log::Error("Couldn't load SDL2! SDL_Init returned %i.", ret);
		throw new std::exception();
	}

	// Create a window
	Window = SDL_CreateWindow("SuperGuy", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!Window) {
		Log::Error("Couldn't load SDL2! SDL_CreateWindow returned NULL");
		throw new std::exception();
	}

	// Create the renderer for the window.
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if (!Renderer) {
		Log::Error("Couldn't load SDL2! SDL_CreateRenderer returned NULL");
		throw new std::exception();
	}

	if (IMG_Init(IMG_INIT_PNG)) {
		Log::Error("Couldn't init SDL2_image!");
		throw new std::exception();
	}

	Log::Info("Initialized SDL2 successfully!");
}

Engine::Engine() {
	Log::Info("Initalizing SuperGuy...");

	// Initialize SDL.
	InitSDL();

	// Create a new dvar manager and register the cheats dvar.
	DvarMgr = new DvarManager("dvar.cfg");
	Cheats = DvarMgr->RegisterDvar(
			new Dvar("cheats", "Enables cheats", DVAR_FLAG_ARCHIVED, true));
	Log::Info("Initialized SuperGuy successfully!");
	this->CurrentState = NULL;
}

Engine::~Engine() {
	delete DvarMgr;
	if (Renderer)
		SDL_DestroyRenderer(Renderer);
	if (Window)
		SDL_DestroyWindow(Window);
	SDL_Quit();
	Log::Info("Shutting down SuperGuy, Bye!");
}

void Engine::Run() {
	bool quit = false;
	SDL_Event event;
	double delta = 1.0;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT
					|| (event.type == SDL_KEYDOWN
							&& event.key.keysym.sym == SDLK_ESCAPE))
				quit = true;

			if (this->CurrentState)
				this->CurrentState->OnEvent(event);
		}
		if (this->CurrentState)
			this->CurrentState->OnUpdate(delta);

		SDL_RenderClear(this->Renderer);

		if (this->CurrentState)
			this->CurrentState->OnRender(this->Renderer);

		SDL_RenderPresent(this->Renderer);
	}
}

DvarManager * Engine::GetDvarMgr() {
	return this->DvarMgr;
}
