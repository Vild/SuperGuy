/* ============================================================================
 * Name        : State.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

#ifndef STATE_H_
#define STATE_H_
#include <SDL2/SDL.h>

class State {
public:
	State();
	virtual ~State();
	virtual void OnEvent(SDL_Event event);
	virtual void OnUpdate();
	virtual SDL_Texture * OnRender();
};

#endif /* STATE_H_ */
