TODO
====

* Tile class for each tile.
* Render function/class for putting all tiles into a world texture (SDL_Texture) for rendering.
* Entity class for AI, the player, coin, etc
* Tilesheet for tiles and entities
* Map loading, (texture in map file?)
* Map editor (In-game?)
* Music/Sound effects

Main loop
=========

1. If any tiles has changed, rerender world texture
2. Render the world texture to the screen
3. Render all entitys to the screen
4. Goto #1
