//
// Created by semyon on 19.06.19.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class MapEditor;

class Player
 {

private:
	AnimationManager anim;
	float posX, posY, dx, dy;
	float speed;
	enum MovementDirection {
		STAY,
		LEFT,
		RIGHT,
		JUMP,
		TOP,
		DOWN
	};
	sf::Sprite sprite;
	MovementDirection state;

	bool playerOnGround;

	

	bool life;
	unsigned hp;


public:
	Player(float x, float y, sf::Texture & texture,  std::string anim_file);
	virtual ~Player();

	const bool& checkLife() const;

	void movement(float time);
	void checkCollision(float Dx,float Dy);

	const sf::FloatRect& getRect() const;

	virtual const sf::Vector2f& getPosition() const;

	const float & getDirectionX() const;
	const float & getDirectionY() const;

	void setPosition(const float x,const float y);

	void setCollisionX(bool collis);
	void setCollisionY(bool collis);

	void update(float time);

	void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_PLAYER_H