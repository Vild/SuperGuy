/*
 * AIEntity.h
 *
 *  Created on: Mar 25, 2013
 *      Author: ludkiller
 */

#ifndef AIENTITY_H_
#define AIENTITY_H_

class aiEntity {
public:
	SDL_Rect ai;
	int speedX;
	int speedY;
	float alpha;
	float rotation;
	aiEntity();
	~aiEntity();
};


#endif /* AIENTITY_H_ */
