/*
 * enemy_duck.h
 *
 *  Created on: Mar 24, 2013
 *      Author: ludkiller
 */

#ifndef ENEMY_DUCK_H_
#define ENEMY_DUCK_H_

class enemyDuck: private aiEntity {
public:
	enemyDuck();
	~enemyDuck();
	void destroyMe();

};

#endif /* ENEMY_DUCK_H_ */
