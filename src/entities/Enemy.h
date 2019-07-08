#ifndef ENEMY_H
#define ENEMY_H


#include "Bullet.h"


class Enemy
{
private:
	sf::RenderWindow * window;
	float posX, posY, dx, dy;
	float speed;
	enum MovementDirection {
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
	float width, height, rectX, rectY;
	int bulletState;
	bool enemyOnGround;
	sf::Clock timer;
	std::vector<Bullet*> bullets;
	std::vector<Bubble*> bubbles;
	float sleep;
	float timerValue;
	bool ShootMode;
public:
	Enemy(sf::RenderWindow *window, std::string path, float x, float y);
	virtual ~Enemy();


	void checkCollision(float Dy, float Dx, sf::RectangleShape *object);
	void update(float time, sf::RectangleShape *object);
	float getPositionX();
	float getPositionY();
	void render(sf::RenderWindow * window);
};



#endif // ! ENEMY_H