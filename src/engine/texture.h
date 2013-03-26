/* ============================================================================
 * Name        : texture.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>

class texture {
public:
	/*! \brief Makes a new texture of the file \a file and it has \a count of sprites.
	 \param file The name of the dvar.
	 \param count The description of the dvar.
	 */
	texture(const char * file, int count);
	~texture();

	/*! \brief Gets a texture at a specific position.
	 \param pos The position.
	 \return The texture.
	 */
	texture * getTextureAtPos(int pos);
	/*! \brief Converts the texture to a SDL_Surface.
	 \return The surface.
	 */
	SDL_Surface * getTexture();

private:
	SDL_Surface * tex;
	SDL_Rect size;
	int countPerRow;

	SDL_Surface * loadImage(const char * file);
	texture(SDL_Surface * tex);
};

#endif /* TEXTURE_H_ */
