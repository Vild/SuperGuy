/*
 * enemy_duck.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef ENEMY_DUCK_H_
#define ENEMY_DUCK_H_

class enemyDuck: public aiEntity {
public:
	enemyDuck();
	enemyDuck(int _x, int _y, int _w, int _h);
	enemyDuck(int _x, int _y, int _w, int _h, int _speedX, int _speedY);
	~enemyDuck();
	void destroyMe();

};

#endif /* ENEMY_DUCK_H_ */
