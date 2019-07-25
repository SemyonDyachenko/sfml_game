//
// Created by semyon on 19.06.19.
//

#include "Player.h"
#include "../Collision.h"




Player::Player(sf::RenderWindow *window,std::string path,float x,float y)
{
this->window = window;
this->width = 32;
this->height = 1;
this->rectX = 0;
this->rectY = 0;
this->path = path;
this->speed= 0;
if(!this->image.loadFromFile(path)) std::cout << "error:not load image file" << path << std::endl;
//this->shape.setSize(sf::Vector2f(texture.getSize().x,texture.getSize().y));
this->texture.loadFromImage(this->image);
anim.loadFromXML("../res/animation/anim.xml", this->texture);
this->posX = x;
this->posY = y-this->height;
this->state = STAY;
currentFrameTime = 0;
this->playerOnGround = false;
this->bulletState = 0;
this->sleep = 0;
this->ShootMode = 1;
this->timerValue = 500;
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
			anim.set("stayleft");
		}
		else if(this->state == RIGHT) 
		{
			anim.set("stayright");
		}
	}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X)) > 1) 
{
		this->state = RIGHT; this->speed = 0.1f;
		anim.set("walkright");
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) < 0) 
{
		this->state = LEFT; this->speed = 0.1f;
		anim.set("walkleft");
}
if (this->playerOnGround == true)
{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Joystick::isButtonPressed(0, 1)))
		{
		this->state = JUMP;
		this->dy = -0.4f;
		this->playerOnGround = false;
		}
	}	
}


const sf::Vector2f & Player::getPosition() const 
{
	return this->sprite.getPosition();
}

void Player::update(float time)
{
	if (this->life)
	{
		movement(time);
		switch (state) {

		case STAY:break;
		case LEFT:this->dx = -speed; break;
		case RIGHT:this->dx = speed; break;
		case JUMP: break;
		}

		this->posX += dx * time;
		this->posY += dy * time;
		this->speed = 0;
		this->sprite.setPosition(posX, posY);
		this->dy = dy + 0.0014*time;

		this->timerValue = 500;
	

		if (playerOnGround)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))

			{

				if (this->state == LEFT) {
					anim.set("attackleft");
				}
				else if (this->state == RIGHT)
				{
					anim.set("attackright");
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) < 0))
				{
					/*	this->bulletState = 3;


						if (timer.getElapsedTime().asMilliseconds() > 500) 
						{
							timer.restart();
							this->bullets.push_back(new Bullet(this->window, bulletState, posX + this->width / 2, this->posY));
						}


					}
					else 
					{
						if (this->state == LEFT) 
						{
							this->bulletState = 1;

							if (timer.getElapsedTime().asMilliseconds() > 500) 
							{

								timer.restart();
								this->bullets.push_back(new Bullet(this->window, bulletState, this->posX, posY + this->height / 2));
							}
							
						}

						if (this->state == RIGHT)
						{
							this->bulletState = 2;
							if (timer.getElapsedTime().asMilliseconds() > 500) 
							{
								timer.restart();
								this->bullets.push_back(new Bullet(this->window, bulletState, this->posX + width, posY + this->height / 2));
							}
						}


						if (this->state == JUMP) 
						{
							if (this->rectY == 0) {
								if (timer.getElapsedTime().asMilliseconds() > 500) 
								{
									timer.restart();
										this->bullets.push_back(new Bullet(this->window, bulletState, this->posX + width, posY + this->height / 2));

								}
							}
							if (this->rectY >= 153) 
							{
								if (timer.getElapsedTime().asMilliseconds() > 500) 
								{
									timer.restart();
									this->bullets.push_back(new Bullet(this->window, bulletState, this->posX, posY + this->height / 2));
								}
							}
						}
					}
				}*/



				}
			}
		}


		if (bullets.size() != 0)
		{

			for (size_t i = 0; i < bullets.size(); i++)
			{
				if (bullets[i]->getAlive())
				{
					bullets[i]->update(time);
				}
			}
		}


	

		for (size_t i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->getAlive() == false)
			{
				bullets.erase(bullets.begin() + i);
			}
		}



	}

	if (this->posY > 650)
	{
		this->posY = 650 - 45;
	}


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
	anim.draw(*window,this->posX,this->posY);

	if (bullets.size() != 0) 
	{
		for (size_t i = 0; i < bullets.size(); i++) 
		{
			if (bullets[i]->getAlive()== true) 
			{
				bullets[i]->render(window);
			}
		}
	}

}


