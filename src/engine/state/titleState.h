/* ============================================================================
 * Name        : titleState.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef TITLESTATE_H_
#define TITLESTATE_H_

#include "stateMachine.h"

class titleStage: public state {
public:
	titleStage(); ///Constructor for Title
	~titleStage(); ///Destructor for Title
	void handle_events(); ///Handle Title Events
	void logic(); ///Handle Title Logic
	void render(); ///Handle Title Rendering

private:
	SDL_Surface * background; ///Title Background
	SDL_Surface * message; ///Title Message
};

#endif /* TITLESTAGE_H_ */
