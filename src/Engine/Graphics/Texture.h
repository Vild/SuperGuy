/* ============================================================================
 * Name        : Texture.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>

class Texture {
public:
	/*! \brief Makes a new texture of the file \a file and it has \a count of sprites.
	 \param file The name of the dvar.
	 \param count The description of the dvar.
	 */
	Texture(const char * file, int count);
	~Texture();

	/*! \brief Gets a texture at a specific position.
	 \param pos The position.
	 \return The texture.
	 */
	Texture * GetTextureAtPos(int pos);
	/*! \brief Converts the texture to a SDL_Surface.
	 \return The surface.
	 */
	SDL_Surface * GetTexture();

private:
	SDL_Surface * Tex;
	SDL_Rect Size;
	int CountPerRow;

	SDL_Surface * LoadImage(const char * file);
	Texture(SDL_Surface * tex);
};

#endif /* TEXTURE_H_ */
