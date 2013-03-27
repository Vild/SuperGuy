/* ============================================================================
 * Name        : overWorldState.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef OVERWORLDSTATE_H_
#define OVERWORLDSTATE_H_

#include "stateMachine.h"

class overWorldState: public state {
public:
	overWorldState();
	~overWorldState();
	void handle_events();
	void logic();
	void render();
};

#endif /* OVERWORLDSTAGE_H_ */
