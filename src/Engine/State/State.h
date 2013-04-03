/* ============================================================================
 * Name        : State.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : FreeBSD
 * Description : State class
 * ============================================================================ */

#ifndef STATE_H_
#define STATE_H_
#include <SDL2/SDL.h>

/*! \brief State class
 */
class State {
public:
	/*! \brief Sets up internal stuff for the different states.
	 */
	State();
	virtual ~State();

	/*! \brief This will be called when theirs an event.
	 \param event The event.
	 */
	virtual void OnEvent(SDL_Event event);
	/*! \brief This will be called when it's time for an update.
	 \param delta The time different between the updates.
	 */
	virtual void OnUpdate(double delta);
	/*! \brief This will be called when it's time for a render.
	 \param renderer The renderer for the game screen, that we will render to.
	 */
	virtual SDL_Texture * OnRender(SDL_Renderer * renderer);
};

#endif /* STATE_H_ */
