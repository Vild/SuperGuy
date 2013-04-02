/* ============================================================================
 * Name        : Engine.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include "Data/DvarManager.h"
#include "State/State.h"

class Engine {
public:
	Engine();
	~Engine();

	void Run();

	DvarManager * DvarMgr;
private:
	SDL_Window * Window;
	SDL_Renderer * Renderer;

	Dvar * Cheats;

	State * CurrentState;

	void InitSDL();
};

extern Engine * EngineInstance;

#endif /* ENGINE_H_ */
