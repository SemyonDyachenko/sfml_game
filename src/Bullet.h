//
// Created by semyon on 22.06.19.
//

#ifndef CATCHONBUBBLE_BULLET_H
#define CATCHONBUBBLE_BULLET_H


#include <iostream>
#include <string>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <GL/gl.h>
#include <GL/glut.h>

class Bullet {
protected:
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;

    float posX,posY,speed;
    int state;

public:
    Bullet();
    ~Bullet();


    void update();
    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_BULLET_H
