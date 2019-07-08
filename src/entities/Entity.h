#ifndef ENTITY_H
#define ENTITY_H

#include "Bullet.h"

class Entity
{
private:
	sf::RenderWindow * window; float posX, posY, dx, dy;
	float speed; enum MovementDirection {
		STAY,
		LEFT,
		RIGHT,
		JUMP
	};
	sf::Sprite sprite;
	sf::Image image;
	sf::Texture texture;
	std::string path;
	MovementDirection state;
	float currentFrameTime;
	float width, height;
public:
	Entity();
	virtual ~Entity();
};



#endif // ! ENTITY_H
