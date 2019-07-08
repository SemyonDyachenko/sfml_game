#ifndef BUBBLE_H
#define BUBBLE_H

#include <stack>
#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <glut.h>
#include <thread>
#include <chrono>

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