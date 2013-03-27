/* ============================================================================
 * Name        : engine.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include "data/dvarManager.h"
#include "state/stateMachine.h"

class engine {
public:
	engine();
	~engine();

	dvarManager * dvarMgr;
private:
	SDL_Window * window;
	SDL_Renderer * renderer;

	dvar * cheats;

	state * currentState;

	void init_sdl();
};

extern engine * engineInstance;

#endif /* ENGINE_H_ */
