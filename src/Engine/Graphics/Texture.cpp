/* ============================================================================
 * Name        : Texture.cpp
 * Author(s)   : Dan "WildN00b" Printzell
 * Copyright   : GPLv2, i think
 * Description : 
 * ============================================================================ */

#include "Texture.h"
#include "../../Log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Surface * Texture::LoadImage(const char * file) {
	// Return the loaded image.
	return IMG_Load(file);
}

Texture::Texture(const char * file, int count) {
	// Load the image and set up the size for the image.
	this->Tex = LoadImage(file);
	if (this->Tex == NULL)
		Log::Error("Couldn't load \"%s\"", file);
	this->CountPerRow = sqrt(count);
	this->Size.h = this->Tex->h;
	this->Size.w = this->Tex->w;
	this->Size.x = 0;
	this->Size.y = 0;
}

Texture::Texture(SDL_Surface * surface) {
	// Set up the size for the surface and save the surface.
	this->Tex = surface;
	this->CountPerRow = 1;
	this->Size.h = surface->h;
	this->Size.w = surface->w;
	this->Size.x = 0;
	this->Size.y = 0;
}

Texture::~Texture() {
	// Free the surface.
	SDL_FreeSurface(this->Tex);
}

Texture * Texture::GetTextureAtPos(int pos) {
	const int size = this->Size.h / this->CountPerRow;
	const SDL_PixelFormat * format = this->Tex->format;
	SDL_Rect srcPos;
	SDL_Rect destPos;
	// Create a new surface for holder the new texture.
	SDL_Surface * newtex = SDL_CreateRGBSurface(SDL_SWSURFACE, size, size,
			format->BitsPerPixel, format->Rmask, format->Gmask, format->Bmask,
			format->Amask);

	// Return NULL if it failed to create the surface.
	if (newtex == NULL) {
		Log::Error("Failed to get texture at pos \"%i\"", pos);
		return NULL;
	}

	// Setting where to draw from and to.
	srcPos.x = pos % CountPerRow;
	srcPos.y = pos / CountPerRow;
	srcPos.w = size;
	srcPos.h = size;
	destPos.x = 0;
	destPos.y = 0;
	destPos.w = size;
	destPos.h = size;

	// Blit the texture from the old to the new surface
	if (SDL_BlitSurface(this->Tex, &srcPos, newtex, &destPos) != 0) {
		Log::Error("Failed blit texture at pos \"%i\"", pos);
		return NULL;
	}

	return new Texture(newtex);
}

SDL_Surface * Texture::GetTexture() {
	// Returns the surface.
	return this->Tex;
}
