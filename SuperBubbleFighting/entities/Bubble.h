#ifndef BUBBLE_H
#define BUBBLE_H

#include "Tile.h"

class Bubble
{
private:
	sf::RenderWindow *window;
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string path;
	float posX, posY, speedX, speedY;
	int state;
	bool isAlive;

public:
	Bubble(sf::RenderWindow * window, int state, float x, float y);
	
	bool getAlive();
	void setAlive(bool alive);
	sf::FloatRect getRect();
	void update(float time);
	void render(sf::RenderWindow * window);

	virtual ~Bubble();
};



#endif // BUBLE_H