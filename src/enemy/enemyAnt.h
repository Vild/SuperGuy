/*
 * enemy.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef ENEMY_H_
#define ENEMY_H_

class enemyAnt {
private:
	SDL_Rect ant;
	int speedX;
	int speedY;
	float alpha;
	float rotation;
public:
	enemyAnt();
	~enemyAnt();
	void destroyMe();

};

#endif /* ENEMY_H_ */
