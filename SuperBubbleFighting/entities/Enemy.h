#ifndef ENEMY_H
#define ENEMY_H


#include "Bullet.h"
#include "../animation/AnimationManager.h"


class Enemy
{
private:
	float posX, posY, dx, dy;
	float speed;
	enum MovementDirection {
		stay,
		walkleft,
		walkright,
		die,
		attackleft,
		attackright
	};
	MovementDirection state;
	sf::Sprite sprite;
	float currentFrameTime;
	float width, height;
	AnimationManager animation;
	bool onGround;
	
	sf::Font font;
	sf::Text text;
	sf::String str;

	void initText();


	bool life;
public:
	Enemy(std::string name, float x, float y, sf::Texture& texture, std::string anim_path,unsigned hp);
	virtual ~Enemy();

	unsigned hp;

	bool checkLife();

	sf::FloatRect getRect();

	void  checkCollision(float Dy, float Dxá ,sf::RectangleShape*object=0);
	void  update(float time, sf::RectangleShape*object=0);
	float getPositionX();
	float getPositionY();
	void  render(sf::RenderWindow * window);
};



#endif // ! ENEMY_H