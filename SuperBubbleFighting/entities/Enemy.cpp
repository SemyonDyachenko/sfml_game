#include "Enemy.h"



void Enemy::initText()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf")) std::cout << "error load font in player\n";
	this->text.setFont(font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::Black);
}

Enemy::Enemy(std::string name, float x, float y, sf::Texture & texture,std::string anim_path,unsigned hp)
{
	this->initText();
	this->posX = x;
	this->posY = y;
	this->sprite.setTexture(texture);
	this->sprite.setPosition(x, y);
	this->width = 60;
	this->height = 2;
	this->state = stay;
	this->animation.loadFromXML(anim_path, texture);
	this->animation.set("stay");
	this->onGround = false;
	this->dx = 0; this->dy = 0;
	this->hp = hp;
	this->life = true;
}

Enemy::~Enemy()
{
}


bool Enemy::checkLife()
{
	return this->life;
}

sf::FloatRect Enemy::getRect()
{
	return sf::FloatRect(this->posX,this->posY,this->width,this->height);
}

void Enemy::checkCollision(float Dy, float Dx, sf::RectangleShape*object)
{
	if (sf::FloatRect(posX, posY, width, height).intersects(sf::FloatRect(object->getPosition().x, object->getPosition().y, object->getSize().x, object->getSize().y)))
	{
		if (Dy > 0) { this->posY = object->getPosition().y - height; this->dy = 0; this->onGround = true; }
	}
}

void Enemy::update(float time, sf::RectangleShape*object)
{
	if (life ==true) {
		this->checkCollision(this->posX, this->posY, object);
		this->dy = dy + 0.0014*time;
		this->posY += this->dy*time;
		this->sprite.setPosition(this->posX, this->posY);

		this->animation.tick(time);
	}

	this->str = std::to_string(this->hp);
	this->text.setString(str);
	this->text.setPosition(this->posX, this->posY - 50);

	if (this->hp <= 0)
	{
		this->life = false;
	}
	else
	{
		this->life = true;

	}
}

float Enemy::getPositionX()
{
	return this->posX;
}

float Enemy::getPositionY()
{
	return this->posY;
}

void Enemy::render(sf::RenderWindow * window)
{
	this->animation.draw(*window, this->posX, this->posY);
	window->draw(this->text);
}
