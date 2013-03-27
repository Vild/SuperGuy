/* ============================================================================
 * Name        : texture.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include "texture.h"
#include "../../log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>

SDL_Surface * texture::loadImage(const char * file) {
	// Return the loaded image.
	return IMG_Load(file);
}

texture::texture(const char * file, int count) {
	// Load the image and set up the size for the image.
	this->tex = loadImage(file);
	if (this->tex == NULL)
		log::error("Couldn't load \"%s\"", file);
	this->countPerRow = sqrt(count);
	this->size.h = this->tex->h;
	this->size.w = this->tex->w;
	this->size.x = 0;
	this->size.y = 0;
}

texture::texture(SDL_Surface * surface) {
	// Set up the size for the surface and save the surface.
	this->tex = surface;
	this->countPerRow = 1;
	this->size.h = surface->h;
	this->size.w = surface->w;
	this->size.x = 0;
	this->size.y = 0;
}

texture::~texture() {
	// Free the surface.
	SDL_FreeSurface(this->tex);
}

texture * texture::getTextureAtPos(int pos) {
	const int size = this->size.h / this->countPerRow;
	const SDL_PixelFormat * format = this->tex->format;
	SDL_Rect srcPos;
	SDL_Rect destPos;
	// Create a new surface for holder the new texture.
	SDL_Surface * newtex = SDL_CreateRGBSurface(SDL_SWSURFACE, size, size,
			format->BitsPerPixel, format->Rmask, format->Gmask, format->Bmask,
			format->Amask);

	// Return NULL if it failed to create the surface.
	if (newtex == NULL) {
		log::error("Failed to get texture at pos \"%i\"", pos);
		return NULL;
	}

	// Setting where to draw from and to.
	srcPos.x = pos % countPerRow;
	srcPos.y = pos / countPerRow;
	srcPos.w = size;
	srcPos.h = size;
	destPos.x = 0;
	destPos.y = 0;
	destPos.w = size;
	destPos.h = size;

	// Blit the texture from the old to the new surface
	if (SDL_BlitSurface(this->tex, &srcPos, newtex, &destPos) != 0) {
		log::error("Failed blit texture at pos \"%i\"", pos);
		return NULL;
	}

	return new texture(newtex);
}

SDL_Surface * texture::getTexture() {
	// Returns the surface.
	return this->tex;
}
