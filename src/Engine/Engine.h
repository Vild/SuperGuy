/* ============================================================================
 * Name        : Engine.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : Game engine class
 * ============================================================================ */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include "Data/DvarManager.h"
#include "State/State.h"

/*! \brief Game engine class
 */
class Engine {
public:
	/*! \brief The constructor for the engine class.
	 */
	Engine();
	~Engine();

	/*! \brief You call this when you have setup everything and want to engine to do it's thing.
	 */
	void Run();

	/*! \brief This will return the dvar manager for registering dvars.
	 \return The dvar manager.
	 */
	DvarManager * GetDvarMgr();

private:
	SDL_Window * Window;
	SDL_Renderer * Renderer;

	DvarManager * DvarMgr;
	Dvar * Cheats;

	State * CurrentState;

	void InitSDL();
};

#endif /* ENGINE_H_ */
