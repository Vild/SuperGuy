/*
 * enemy.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */
#include"enemyAnt.h"
#include<SDL2/SDL.h>

enemyAnt::enemyAnt() {
	this->ant.x= 0;
	this->ant.y= 0;
	this->ant.h= 0;
	this->ant.w= 0;
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
