/*
 * enemy.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */
#include"enemyAnt.h"
#include<SDL2/SDL.h>
#include"AIEntity.h"

enemyAnt::enemyAnt() {
	this->entity.x = 0;
	this->entity.y = 0;
	this->entity.h = 0;
	this->entity.w = 0;
	this->alpha = 0.8;
	this->rotation = 0;
	this->speedX = 0;
	this->speedY = 0;

}

enemyAnt::~enemyAnt() {
	delete this;
}

void enemyAnt::destroyMe() {

}
