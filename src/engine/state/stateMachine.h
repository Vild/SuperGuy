/* ============================================================================
 * Name        : stateMachine.h
 * Author(s)   : ludkiller
 * Copyright   : FreeBASH
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

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include <iostream>
#include <SDL2/SDL.h>

class state {
public:
	virtual ~state() = 0; ///Destructor for each state
	virtual void handle_events() = 0; ///Handle events for every state
	virtual void logic() = 0; ///Handle Logic for each state
	virtual void render() = 0; ///Handle rendering for each state
};

#endif /* STATEMACHINE_H_ */
