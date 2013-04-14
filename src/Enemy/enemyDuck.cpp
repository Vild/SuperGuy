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

enemyDuck::~enemyDuck() {
	delete this;
}

void enemyDuck::destroyMe() {

}

