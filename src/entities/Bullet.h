//
// Created by semyon on 22.06.19.
//

#ifndef CATCHONBUBBLE_BULLET_H
#define CATCHONBUBBLE_BULLET_H

#include "Bubble.h"


class Bullet {

public:

	sf::RenderWindow *window;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
	std::string path;

    float posX,posY,speedX,speedY;
    int state;
	bool isAlive;

    Bullet(sf::RenderWindow* widnow,int state,float x,float y);
    ~Bullet();

	bool getAlive();
	void setAlive(bool alive);
	sf::FloatRect getRect();
    void update(float time);
    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_BULLET_H
