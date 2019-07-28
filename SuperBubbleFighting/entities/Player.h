//
// Created by semyon on 19.06.19.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player {
protected:
	AnimationManager anim;
	float posX, posY, dx, dy;
	float speed;
	enum MovementDirection {
		STAY,
		LEFT,
		RIGHT,
		JUMP,
		TOP
	};
	sf::Sprite sprite;
	MovementDirection state;

	bool playerOnGround;

	MapEditor* level;

	bool life;
	unsigned hp;


public:
	Player(float x, float y, sf::Texture & texture, MapEditor & level, std::string anim_file);
	virtual ~Player();

	const bool& checkLife() const;

	void movement(float time);
	void checkCollision(float Dx,float Dy);

	virtual const sf::Vector2f& getPosition() const;

	void update(float time);

	void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_PLAYER_H