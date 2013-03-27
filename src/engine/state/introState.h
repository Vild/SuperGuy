/* ============================================================================
 * Name        : introState.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef INTROSTATE_H_
#define INTROSTATE_H_

#include "stateMachine.h"

class introState: public state {
public:
	introState(); ///Constructor for Intro
	~introState(); ///Destructor for Intro
	void handle_events(); ///Handle Intro Events
	void logic(); ///Handle Intro Logic
	void render(); ///Handle Intro Rendering
private:
	SDL_Surface * background; ///Intro Background
	SDL_Surface * message; ///Intro Message
};

#endif /* INTROSTAGE_H_ */
