#ifndef PLAYER_H
#define PLAYER_H

#include "Tile.h"
#include "../animation/AnimationManager.h"



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

	void initDefaultVariables();

public:
	Player(float x, float y,sf::Texture & texture, std::string anim_file);
	virtual ~Player();

	const bool& checkLife() const;

	void movement(float time);

	void moveLeft();
	void moveRight();
	void jump();

	void checkCollision(float Dx,float Dy);

	const sf::FloatRect& getRect() const;
	const sf::FloatRect& getGlobalBounds() const;

	const sf::Vector2f& getPosition() const;

	void setPosition(const float x,const float y);

	void updateLife();

	void levelUp();

	void updateCollider(float time);
	void update(float time);

	void renderCollider(sf::RenderWindow * window);
	void render(sf::RenderWindow * window);
};


#endif // PLAYER_H