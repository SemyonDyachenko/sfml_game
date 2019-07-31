//
// Created by semyon on 19.06.19.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Tile.h"
#include "../animation/AnimationManager.h"
#include "MapEditor.h"

class Entity;
class MapEditor;
class AnimationManager;


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
	};
	sf::Sprite sprite;
	MovementDirection state;
	
	bool playerOnGround;

	sf::RectangleShape collider2D;

	bool life;
	unsigned hp;


public:
	Player(float x, float y, sf::Texture & texture,  std::string anim_file);
	virtual ~Player();

	const bool& checkLife() const;

	void movement(float time);
	void checkCollision(float Dx,float Dy);

	const sf::FloatRect& getRect() const;
	const sf::FloatRect& getGlobalBounds() const;

	virtual const sf::Vector2f& getPosition() const;

	const float & getDirectionX() const;
	const float & getDirectionY() const;

	void setPosition(const float x,const float y);

	void setCollisionX(bool collis);
	void setCollisionY(bool collis);

	void updateCollider(float time);
	void update(float time);

	void renderCollider(sf::RenderWindow * window);
	void render(sf::RenderWindow * window);
};


#endif // PLAYER_H