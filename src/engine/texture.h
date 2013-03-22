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
	texture(const char * file, int count);
	texture(SDL_Surface * tex);
	~texture();

	texture * getTextureAtPos(int pos);
	SDL_Surface * getTexture();

private:
	SDL_Surface * tex;
	SDL_Rect size;
	int countPerRow;

	SDL_Surface * loadImage(const char * file);
};

#endif /* TEXTURE_H_ */
