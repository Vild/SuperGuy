/*
 * enemy_duck.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#include"enemyDuck.h"
#include<SDL2/SDL.h>

enemyDuck::enemyDuck() {
	this->entity.x = 0;
	this->entity.y = 0;
	this->entity.h = 0;
	this->entity.w = 0;
	this->alpha = 0.8;
	this->rotation = 0;
	this->speedX = 0;
	this->speedY = 0;

}

enemyDuck::enemyDuck(int _x, int _y, int _w, int _h) {
	this->entity.x = _x;
	this->entity.y = _y;
	this->entity.w = _w;
	this->entity.h = _h;
	this->alpha = 0.8;
	this->rotation = 0;
	this->speedX = 0;
	this->speedY = 0;
}
enemyDuck::enemyDuck(int _x, int _y, int _w, int _h, int _speedX, int _speedY) {
	this->entity.x = _x;
	this->entity.y = _y;
	this->entity.w = _w;
	this->entity.h = _h;
	this->speedX = _speedX;
	this->speedY = _speedY;
	this->alpha = 0.8;
	this->rotation = 0;
}

enemyDuck::~enemyDuck() {
	delete this;
}

void enemyDuck::destroyMe() {

}

