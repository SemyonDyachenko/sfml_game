#ifndef SFMLOBJECT_H
#define SFMLOBJECT_H


#include "MapObject.h"

class SFMLObject
{
public:
	SFMLObject();
	virtual ~SFMLObject();

	virtual void update(float time);
	virtual void render(sf::RenderWindow * window);
};

#endif