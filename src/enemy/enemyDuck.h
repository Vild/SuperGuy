/*
 * enemy_duck.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef ENEMY_DUCK_H_
#define ENEMY_DUCK_H_

class enemyDuck {
private:
	SDL_Rect duck;
	int speedX;
	int speedY;
	float alpha;
	float rotation;
public:
	enemyDuck();
	~enemyDuck();
	void destroyMe();

};


#endif /* ENEMY_DUCK_H_ */
