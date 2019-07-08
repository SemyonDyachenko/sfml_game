#include "Enemy.h"



Enemy::Enemy(sf::RenderWindow * window, std::string path, float x, float y)
{
	this->window = window;
	this->width = 103;
	this->height = 147;
	this->rectX = 0;
	this->rectY = 0;
	this->path = path;
	this->speed = 0;
	if (!this->image.loadFromFile(path)) std::cout << "error:not load image file" << path << std::endl;
	//this->shape.setSize(sf::Vector2f(texture.getSize().x,texture.getSize().y));
	this->texture.loadFromImage(this->image);
	this->sprite.setTexture(this->texture);
	this->posX = x;
	this->posY = y - this->height;
	this->sprite.setPosition(posX, posY);
	this->sprite.setTextureRect(sf::IntRect(rectX, rectY, width, height));
	this->state = STAY;
	currentFrameTime = 0;
	this->enemyOnGround = false;
	this->bulletState = 0;
	this->sleep = 0;
	this->ShootMode = 1;
	this->timerValue = 500;
}

Enemy::~Enemy()
{
}

void Enemy::checkCollision(float Dy, float Dx, sf::RectangleShape * object)
{
}

void Enemy::update(float time, sf::RectangleShape * object)
{
}

float Enemy::getPositionX()
{
	return 0.0f;
}

float Enemy::getPositionY()
{
	return 0.0f;
}

void Enemy::render(sf::RenderWindow * window)
{
}
