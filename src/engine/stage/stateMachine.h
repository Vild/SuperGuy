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
#include<stdio.h>
/// States for State Machine
enum STATES {
	STATE_NULL,	///NULL STATE
	STATE_INTRO, ///INTRO or SPLASH SCREEN STATE
	STATE_TITLE, ///TITLE STATE
	STATE_OVERWORLD,
	STATE_STAGE1, ///STAGE1 can add other Stages later similar to STAGE1
	STATE_STAGE2,
	STATE_GAMEOVER, ///GAMEOVER self explanatory
	STATE_QUIT ///QUIT After Game over or random quit ;3
};

class stateMachine {
public:
	virtual void handle_events() = 0; ///Handle events for every state
	virtual void logic() = 0; ///Handle Logic for each state
	virtual void render() = 0; ///Handle rendering for each state
	virtual ~stateMachine() = 0; ///Destructor for each state
};

class Intro: public stateMachine {
private:
	SDL_Surface * background; ///Intro Background
	SDL_Surface * message; ///Intro Message
public:
	Intro(); ///Constructor for Intro
	~Intro(); ///Destructor for Intro
	void handle_events(); ///Handle Intro Events
	void logic(); ///Handle Intro Logic
	void render(); ///Handle Intro Rendering

};

class Title: public stateMachine {
private:
	SDL_Surface * background; ///Title Background
	SDL_Surface * message; ///Title Message
public:
	Title(); ///Constructor for Title
	~Title(); ///Destructor for Title
	void handle_events(); ///Handle Title Events
	void logic(); ///Handle Title Logic
	void render(); ///Handle Title Rendering

};

class OverWorld: public stateMachine {
public:
	OverWorld(int);
	~OverWorld();
	void handle_events();
	void logic();
	void render();

};
class Stage1: public stateMachine {
private:
	SDL_Surface * background; ///Background of Stage1
	const static int levelWidth = 1024; ///Width Of Stage1
	const static int levelHeight = 768; ///Height Of Stage1
public:
	Stage1(); ///Constructor for Stage1
	~Stage1(); ///Destructor for Stage1
	void handle_events(); ///Handle Stage1 Events
	void logic(); ///Handle Stage1 Logic
	void render(); ///Handle Stage1 Rendering

};
class GameOver: public stateMachine {
private:
	SDL_Surface * background; ///Background for GameOver
	SDL_Surface * message; ///Background for Message
public:
	GameOver(); ///Constructor for GameOver
	~GameOver(); ///Destructor for GameOver
	void handle_events(); ///Handle GameOver Events
	void logic(); ///Handle GameOver Logic
	void render(); ///Handle GameOver Rendering

};

int stateID = STATE_NULL;
int nextState = STATE_NULL;
stateMachine * currentState = NULL;

void setNextState(int newState);	///Sets our next state
void changeState();	///Changes State

#endif /* STATEMACHINE_H_ */
