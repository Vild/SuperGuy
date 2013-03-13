/* ============================================================================
 * Name        : texture.h
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL/SDL.h>

class texture {
public:
	texture(const char * file, int count);
	texture(SDL_Surface * tex);
	~texture();

	texture * getTextureAtPos(int pos);
	SDL_Surface * getSurface();

private:
	SDL_Surface * tex;
	SDL_Rect size;
	int countPerRow;
};

#endif /* TEXTURE_H_ */
