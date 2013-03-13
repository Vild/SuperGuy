/* ============================================================================
 * Name        : texture.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include "texture.h"
#include "../log.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cmath>

SDL_Surface * loadImage(const char * file) {
	SDL_Surface * loadedImage = NULL;
	SDL_Surface * optimizedImage = NULL;

	loadedImage = IMG_Load(file);

	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

		SDL_FreeSurface(loadedImage);

		if (optimizedImage != NULL)
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY,
					SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
	}
	return optimizedImage;
}

texture::texture(const char * file, int count) {
	this->tex = loadImage(file);
	if (this->tex == NULL)
		log::error("Couldn't load \"%s\"", file);
	this->countPerRow = sqrt(count);
	this->size.h = this->tex->h;
	this->size.w = this->tex->w;
	this->size.x = 0;
	this->size.y = 0;

}

texture::texture(SDL_Surface * tex) {
	this->tex = tex;
	this->countPerRow = 1;
	this->size.h = tex->h;
	this->size.w = tex->w;
	this->size.x = 0;
	this->size.y = 0;
}

texture::~texture() {
	SDL_FreeSurface(this->tex);
}

texture * texture::getTextureAtPos(int pos) {
	const int size = this->size.h / this->countPerRow;
	const SDL_PixelFormat * format = SDL_GetVideoSurface()->format;
	SDL_Surface * newtex = SDL_CreateRGBSurface(SDL_SWSURFACE, size, size,
			format->BitsPerPixel, format->Rmask, format->Gmask, format->Bmask,
			format->Amask);
	SDL_Rect destPos;
	destPos.x = 0;
	destPos.y = 0;
	destPos.w = size;
	destPos.h = size;
	SDL_Rect srcPost;
	srcPost.x = pos % countPerRow;
	srcPost.y = pos / countPerRow;
	srcPost.w = size;
	srcPost.h = size;

	if (newtex == NULL) {
		log::error("Failed to get texture at pos \"%i\"", pos);
		return NULL;
	}

	if (SDL_BlitSurface(this->getSurface(), &srcPost, newtex, &destPos) != 0) {
		log::error("Failed blit texture at pos \"%i\"", pos);
		return NULL;
	}

	return new texture(newtex);
}

SDL_Surface * texture::getSurface() {
	return this->tex;
}

