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
enemyAnt::enemyAnt(int _x, int _y, int _w, int _h) {
	this->entity.x = _x;
	this->entity.y = _y;
	this->entity.w = _w;
	this->entity.h = _h;
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
