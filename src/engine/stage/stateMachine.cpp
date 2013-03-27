/* ============================================================================
 * Name        : stateMachine.cpp
 * Author(s)   : ludkiller
 * Copyright   : FreeBSD
 * Description : 
 * ============================================================================ */

/* FINITE STATE MACHINE
 * The machine is in only one state at a time;
 * the state it is in at any given time is called the current state.
 * It can change from one state to another when initiated by a triggering event or condition;
 * this is called a transition.
 * A particular FSM is defined by a list of its states,
 * and the triggering condition for each transition.
 */

#include "stateMachine.h"

void setNextState(int newState) {
	if (nextState != STATE_QUIT) {
		nextState = newState;
	}
}

void changeState() {
	if (nextState != STATE_NULL) {
		if (nextState != STATE_QUIT) {
			delete currentState;
		}
		switch (nextState) {
		case STATE_TITLE:
			currentState = new Title();
			break;

		case STATE_OVERWORLD:
			currentState = new OverWorld(stateID);
			break;

		case STATE_STAGE1:
			currentState = new Stage1();
			break;
		}

		//Change the current state ID
		stateID = nextState;

		//NULL the next state ID
		nextState = STATE_NULL;
	}
}
