//
// Created by semyon on 19.06.19.
//

#include "Player.h"

Player::Player(std::string path) {
this->path = path;
this->posX = 100;
this->posY = 100;
this->speed= 0;
if(!this->image.loadFromFile(path)) std::cout << "error:not load image file" << path << std::endl;
//this->shape.setSize(sf::Vector2f(texture.getSize().x,texture.getSize().y));
this->texture.loadFromImage(this->image);
this->sprite.setTexture(this->texture);
this->sprite.setPosition(posX,posY);
this->sprite.setTextureRect(sf::IntRect(0,192,96,96));
this->state = STAY;
currentFrameTime = 0;
}

Player::~Player() {

}


void Player::movement(float time) {
if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->state = LEFT; this->speed = 0.15f;
    this->currentFrameTime += time*0.005f;
    if(this->currentFrameTime > 3) { currentFrameTime -= 3; }
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->state = RIGHT; this->speed = 0.15f;
    this->currentFrameTime += time*0.005f;
    if(this->currentFrameTime > 3) currentFrameTime -= 3;
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    this->state = JUMP; this->speed = 0.4f;
    this->currentFrameTime += time*0.005f;
    if(this->currentFrameTime > 3) currentFrameTime -= 3;
}
}


void Player::update(float time) {
    movement(time);
    switch(state) {

        case STAY:break;
        case LEFT:this->dx = -speed; break;
        case RIGHT:this->dx = speed; break;
        case JUMP:break;
    }

    posX += dx*time;
    posY += dy*time;
    this->sprite.setPosition(posX,posY);
    this->speed = 0;
}

void Player::render(sf::RenderWindow &window) {
window.draw(this->sprite);
}


