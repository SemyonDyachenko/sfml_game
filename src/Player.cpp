//
// Created by semyon on 19.06.19.
//

#include "Player.h"



Player::Player(sf::RenderWindow *window,std::string path,float x,float y) {
this->window = window;
this->width =83;
this->height = 83;
this->path = path;
this->speed= 0;
if(!this->image.loadFromFile(path)) std::cout << "error:not load image file" << path << std::endl;
//this->shape.setSize(sf::Vector2f(texture.getSize().x,texture.getSize().y));
this->texture.loadFromImage(this->image);
this->sprite.setTexture(this->texture);
this->posX = x;
this->posY = y-this->height;
this->sprite.setPosition(posX,posY);
this->sprite.setTextureRect(sf::IntRect(0,192,width,height));
this->state = STAY;
currentFrameTime = 0;
this->playerOnGround = false;
this->onGroundvalue = y;
}

Player::~Player() {

}

void Player::setView(float x, float y) {
this->view.setCenter(x+20,y);
}



void Player::movement(float time) {
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->state = RIGHT; this->speed = 0.25f;
    this->currentFrameTime += time*0.005f;
    if(this->currentFrameTime > 3) { currentFrameTime -= 3; }
    sprite.setTextureRect(sf::IntRect(96 * int(currentFrameTime), 94, 83, 83));
  //  this->setView(posX,posY);
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->state = LEFT; this->speed = 0.25f;
    this->currentFrameTime += time*0.005f;
    if(this->currentFrameTime > 3) currentFrameTime -= 3;
    sprite.setTextureRect(sf::IntRect(96 * int(currentFrameTime), 192, 83, 83));
   // this->setView(posX,posY);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (playerOnGround)) {
    this->state = JUMP;
    this->dy = -0.5f;
    this->playerOnGround = false;
}



}

void Player::checkCollision() {
    if((this->posY+height) > onGroundvalue)
    {
        this->posY = posY - 0.3;
        this->dy = 0;
        this->playerOnGround = true;
    }
     else
    {
        this->playerOnGround = false;
   }

    //
}



void Player::update(float time) {
    movement(time);
    switch(state) {

        case STAY:break;
        case LEFT:this->dx = -speed; break;
        case RIGHT:this->dx = speed; break;
        case JUMP:break;
    }

    this->posX += dx*time;
    checkCollision();
    this->posY += dy*time;
    checkCollision();
    this->speed = 0;
    this->sprite.setPosition(posX,posY);
    this->dy = dy + 0.0015*time;
    checkCollision();

    if(this->posX+width > this->window->getSize().x) {

            this->posX += -0.25*time;
            this->posY += -0.3*time;

    }

    if(this->posX < 0) {

            this->posX += 0.25*time;
            this->posY += -0.3*time;

    }

}

void Player::render(sf::RenderWindow * window) {
window->draw(this->sprite);
}


