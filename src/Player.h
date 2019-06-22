//
// Created by semyon on 19.06.19.
//

#ifndef CATCHONBUBBLE_PLAYER_H
#define CATCHONBUBBLE_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <stack>

class Player {
protected:
    float posX,posY,dx,dy;
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
public:
    sf::View view;
    Player(std::string path);
    virtual ~Player();

    void setView(float x,float y);
    void movement(float time);

    void update(float time);
    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_PLAYER_H
