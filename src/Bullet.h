//
// Created by semyon on 22.06.19.
//

#ifndef CATCHONBUBBLE_BULLET_H
#define CATCHONBUBBLE_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>


class Bullet {

public:

	sf::RenderWindow *window;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;

    float posX,posY,speedX,speedY;
    int state;
	bool isAlive;

    Bullet(sf::RenderWindow* widnow,int state,float x,float y);
    ~Bullet();


    void update(float time);
    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_BULLET_H
