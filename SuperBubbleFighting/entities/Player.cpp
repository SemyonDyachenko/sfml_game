#include "../stdafx.h"
#include "Player.h"


#define KeyA  sf::Keyboard::isKeyPressed(sf::Keyboard::A) 
#define KeyD  sf::Keyboard::isKeyPressed(sf::Keyboard::D) 
#define AxisD sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > 1
#define AxisA  (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) < 0
#define JostickSpace (sf::Joystick::isButtonPressed(0, 1))
#define KeySpace  sf::Keyboard::isKeyPressed(sf::Keyboard::Space)





void Player::initDefaultVariables()
{
	this->speed = 0;
	this->dx = 0; this->dy = 0;
	this->state = STAY;
	this->playerOnGround = false;
	this->hp = 100;
	this->life = true;
}

Player::Player(sf::RenderWindow * window,float x, float y, sf::Texture & texture,std::string anim_file,MapEditor &map)
{
	this->window = window;
	this->posX = x;
	this->posY = y;
	this->map = &map;
	this->collider2D.setPosition(posX, posY);
	this->collider2D.setSize(sf::Vector2f(60,60));
	this->collider2D.setFillColor(sf::Color::Transparent);
	this->collider2D.setOutlineThickness(1.f);
	this->collider2D.setOutlineColor(sf::Color::Green);
	this->anim.loadFromXML(anim_file, texture);
	this->anim.set("run");

	this->buffer.loadFromFile("../res/music/sounds/go.ogg");
	this->sound.setBuffer(buffer);
	this->sound.setLoop(true);
	this->soundplay = false;
}

Player::~Player()
{

}

const bool & Player::checkLife() const
{
	return this->life;
}

void Player::movement(float time)
{
	
	if (!KeyA && !KeyD && !AxisD && !AxisA)
	{

		if (this->state == LEFT)
		{
			this->anim.flip("run");
		}
		if (this->state == RIGHT)
		{
			this->anim.set("run");
		}

	}

	if (KeyD || AxisD)
	{
		this->state = RIGHT; this->speed = 0.2f;
		this->anim.set("run");
	}
	else if (KeyA || AxisA)
	{
		this->state = LEFT; this->speed = 0.2f;
		this->anim.flip("run");
	}

	if ((KeySpace || JostickSpace) && this->playerOnGround)
	{
		this->state = JUMP;
		this->dy = -0.6f;
		this->playerOnGround = false;
	}
}





void Player::checkCollision(float Dy, float Dx)
{
	for (auto &x : this->map->getAllObject())
	{
		for (auto &y : x)
		{
			for (auto *z : y)
			{
				if (z != NULL)
				{
					if (sf::FloatRect(this->posX,this->posY,this->anim.getW(),this->anim.getH()).intersects(z->rect))
					{
					if (z->getName() == "solid")
					{
						if (Dy > 0) { this->posY = z->rect.top - this->anim.getH();  this->dy = 0; this->playerOnGround = true;}
						//if (Dy < 0) { this->posY = z->getGlobalBounds().top + z->getGlobalBounds().height; this->dy = 0; }
						if (Dx > 0) {this->posX = z->rect.left - this->anim.getW(); dx = 0; }
						if (Dx < 0) {this->posX =  z->rect.left + z->rect.width; dx = 0;  }

					}
					else 
					{
						this->playerOnGround = false;
					}

					if (z->getName() == "coin")
					{
						this->map->removeTile(z->rect.left, z->rect.top, 0);
					}

					}
				}
			}
		}
	}
}

const sf::FloatRect & Player::getRect() const
{
	return sf::FloatRect(this->posX, this->posY, 60, 60);
}

const sf::FloatRect & Player::getGlobalBounds() const
{
	return this->collider2D.getGlobalBounds();
}

const sf::Vector2f & Player::getPosition() const
{
	return sf::Vector2f(this->posX, this->posY);
}


void Player::setPosition(const float x, const float y)
{
	this->posX = x;
	this->posY = y;
}

void Player::updateLife()
{
	
	if (this->hp <= 0)
	{
		this->life = false;
	}
	else
	{
		this->life = true;

	}
	
}


void Player::updateCollider(float time)
{
	this->collider2D.setPosition(this->posX, this->posY);
}

void Player::update(float time)
{
		movement(time);
		switch (state) 
		{

		case STAY:break;
		case LEFT:this->dx = -speed; break;
		case RIGHT:this->dx = speed; break;
		case JUMP: break;
		}
		
		this->posX += dx * time;
		this->checkCollision(0,dx);
		this->posY += dy * time;
		this->checkCollision(dy,0);
		this->speed = 0;
		this->collider2D.setPosition(this->posX, this->posY);
		this->dy = dy + 0.0014*time;
		this->updateLife();

			

		anim.tick(time);

}


void Player::renderCollider(sf::RenderWindow * window)
{
	window->draw(this->collider2D);
}

void Player::render(sf::RenderWindow * window)
{
	//this->renderCollider(window);
	this->anim.draw(*window, this->posX, this->posY);
}