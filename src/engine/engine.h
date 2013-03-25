/* ============================================================================
 * Name        : engine.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include "dvar.h"
#include "dvarManager.h"

class engine {
public:
	engine();
	~engine();

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	dvarManager * dvarMgr;

	dvar * cheats;

	void init_sdl();
};

#endif /* ENGINE_H_ */
