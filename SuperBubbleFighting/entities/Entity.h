#ifndef ENTITY_H
#define ENTITY_H

#include "Bullet.h"

class Entity
{
protected:
	float posX, posY, dx, dy;
	float speed;
	enum MovementDirection {
		STAY,
		LEFT,
		RIGHT,
		JUMP
	};
	sf::Sprite sprite;
	MovementDirection state;
	float width, height;
public:
	Entity(std::string name,float x,float y,sf::Texture& texture);
	virtual ~Entity();

	virtual void update(float time) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
};



#endif // ! ENTITY_H
