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
	texture(SDL_Renderer * render, const char * file, int count);
	texture(SDL_Renderer * render, SDL_Surface * tex);
	~texture();

	texture * getTextureAtPos(int pos);
	SDL_Texture * getTexture();

private:
	SDL_Renderer * render;
	SDL_Surface * tex;
	SDL_Texture * retTex;
	SDL_Rect size;
	int countPerRow;

	static SDL_Surface * loadImage(const char * file);
};

#endif /* TEXTURE_H_ */
