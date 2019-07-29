#include "Player.h"





Player::Player(float x, float y, sf::Texture& texture, std::string anim_file)
{
	
	this->speed = 0;
	anim.loadFromXML("../res/animation/anim.xml", texture);
	this->posX = x;
	this->posY = y;
	this->state = STAY;
	this->playerOnGround = false;
	this->hp = 100;
	this->life = true;

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
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (state == STAY)
		{
			
		}

		if (this->state == LEFT)
		{
			anim.flip("stay");
		}
		else if (this->state == RIGHT)
		{
			anim.set("stay");
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) > 1)
	{
		this->state = RIGHT; this->speed = 0.1f;
		anim.set("walk");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) < 0)
	{
		this->state = LEFT; this->speed = 0.1f;
		anim.flip("walk");
	}

		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Joystick::isButtonPressed(0, 1))) && this->playerOnGround)
		{
			this->state = JUMP;
			this->dy = -0.4f;
			this->playerOnGround = false;
		}
}

void Player::checkCollision(float Dx, float Dy)
{
	
}


const sf::FloatRect & Player::getRect() const
{
	return sf::FloatRect(this->posX, this->posY, 35, 35);
}
//}


const sf::Vector2f & Player::getPosition() const
{
	return sf::Vector2f(this->posX, this->posY);
}

const float & Player::getDirectionX() const
{
	if (this->dx == 0)
	{
		return false;
	}
	else
	{
		return this->dx;
	}
}

const float & Player::getDirectionY() const
{
	if (this->dy == 0)
	{
		return false;
	}
	else
	{
		return this->dy;
	}

}

void Player::setPosition(const float x, const float y)
{
	this->posX = x;
	this->posY = y;
}

void Player::setCollisionX(bool collis)
{
	if (collis)
		this->dx = 0;
}

void Player::setCollisionY(bool collis)
{
	if (collis)
	{
		this->dy = 0;
		this->playerOnGround = true;
	}
}

void Player::update(float time)
{
		movement(time);
		switch (state) {

		case STAY:break;
		case LEFT:this->dx = -speed; break;
		case RIGHT:this->dx = speed; break;
		case JUMP: break;
		}

		this->posX += dx * time;
		this->checkCollision(dx, 0);
		this->posY += dy * time;
		this->checkCollision(0, dy);
		this->speed = 0;
		this->sprite.setPosition(posX, posY);
		this->dy = dy + 0.0014*time;


	// life---------------------------------

	if (this->hp <= 0)
	{
		this->life = false;
	}
	else
	{
		this->life = true;

	}

	//-------------------------------w-------

	anim.tick(time);

	

}


void Player::render(sf::RenderWindow * window)
{
	anim.draw(*window, this->posX, this->posY);
}