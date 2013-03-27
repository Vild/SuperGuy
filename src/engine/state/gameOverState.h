/* ============================================================================
 * Name        : gameOverState.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef GAMEOVERSTATE_H_
#define GAMEOVERSTATE_H_

#include "stateMachine.h"

class gameOverState: public state {
public:
	gameOverState(); ///Constructor for GameOver
	~gameOverState(); ///Destructor for GameOver
	void handle_events(); ///Handle GameOver Events
	void logic(); ///Handle GameOver Logic
	void render(); ///Handle GameOver Rendering
private:
	SDL_Surface * background; ///Background for GameOver
	SDL_Surface * message; ///Background for Message
};

#endif /* GAMEOVERSTATE_H_ */
