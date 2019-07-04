//
// Created by semyon on 22.06.19.
//

#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow *window,int state,float x,float y) {
	this->window = window;
	this->path = "../res/images/bullet.png";
	if(!this->image.loadFromFile(path)) {std::cout << "error:don't load image from file for bullet" << "\n"; }
	this->texture.loadFromImage(this->image);
	this->sprite.setTexture(this->texture);
	this->state = state;
	this->speedX = 0; this->speedY = 0;
	this->isAlive = true;
	this->posX = x;
	this->posY = y;
	this->sprite.setPosition(x, y);
}

Bullet::~Bullet() {

}

bool Bullet::getAlive()
{
	return this->isAlive;
}

void Bullet::setAlive(bool alive)
{
	this->isAlive = alive;
}

sf::FloatRect Bullet::getRect()
{
	return sf::FloatRect(posX, posY, this->texture.getSize().x, this->texture.getSize().y);
}

void Bullet::update(float time) {
	//0 - nothing
	//1 - left
	//2 - right
	//3 - up

	if (state == 1) {
		this->speedX = -0.5f;
	}
	else if (state == 2) {
		this->speedX = 0.5f;
	}
	
	if (state == 3) {
		this->speedY = -0.5f;
	}



	if (posX < 0) {
		isAlive = true;
	}
	if (posX > window->getSize().x) {
		isAlive = true;
	}

	if (posY < 0) {
		isAlive = true;
	}

	if (posY > window->getSize().y) {
		isAlive = true;
	}

	this->posX += speedX * time;
	this->posY += speedY * time;

	this->sprite.setPosition(posX, posY);
}

void Bullet::render(sf::RenderWindow *window) {
	if (isAlive==true || this->state != 0) {
		window->draw(this->sprite);
	}
}
