/* ============================================================================
 * Name        : state.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

#ifndef STATE_H_
#define STATE_H_
#include <SDL2/SDL.h>

class state {
public:
	state();
	virtual ~state();
	virtual void onEvent(SDL_Event event);
	virtual void onUpdate();
	virtual SDL_Texture * onRender();
};

#endif /* STATE_H_ */
