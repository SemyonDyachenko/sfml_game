//
// Created by semyon on 19.06.19.
//

#include "Player.h"
#include "../Collision.h"




//shootMode
// 1- bubble
// 0 - bullet

void Player::initText()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf")) std::cout << "error load font in player\n";
	this->text.setFont(font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::Black);
	
}

Player::Player(sf::RenderWindow *window,std::string path,float x,float y)
{
this->window = window;
this->initText();
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

void Player::setView(float x, float y) 
{
this->view.setCenter(x+20,y);
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
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X)) > 1) {
	this->rectX = 150;
	this->rectY = 0;
    this->state = RIGHT; this->speed = 0.1f;
	anim.set("walkright");
  //  this->setView(posX,posY);
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) < 0) {
	this->rectX = 150;
	this->rectY = 153;
    this->state = LEFT; this->speed = 0.1f;
   // this->setView(posX,posY);
	anim.set("walkleft");
}
if (this->playerOnGround == true) {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) || (sf::Joystick::isButtonPressed(0,1))) {
		this->state = JUMP;
			this->dy = -0.4f;
			this->playerOnGround = false;
	}

}

}




void Player::checkCollision(float Dy,float Dx, sf::RectangleShape*object) {
	if (sf::FloatRect(posX, posY, width, height).intersects(sf::FloatRect(object->getPosition().x,object->getPosition().y,object->getSize().x,object->getSize().y)))
	{
		if (Dy > 0) { this->posY = object->getPosition().y - height; this->dy = 0; this->playerOnGround = true; }
   }
    //
}



void Player::update(float time, sf::RectangleShape*object, std::vector<Enemy*>& enemy) 
{
	if (this->life == true)
	{
		movement(time);
		switch (state) {

		case STAY:break;
		case LEFT:this->dx = -speed; break;
		case RIGHT:this->dx = speed; break;
		case JUMP: break;
		}

		this->posX += dx * time;
		checkCollision(dy, dx, object);
		this->posY += dy * time;
		checkCollision(dy, 0, object);
		this->speed = 0;
		this->sprite.setPosition(posX, posY);
		this->dy = dy + 0.0014*time;
		checkCollision(dx, dy, object);



		if (enemy.size() != 0)
		{
			for (size_t i = 0; i < enemy.size(); i++)
			{
				if (sf::FloatRect(this->posX, this->posY, 32, 32).intersects(enemy[i]->getRect()))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
					{
						this->posX = (enemy[i]->getRect().left + enemy[i]->getRect().width) - height;
						enemy[i]->hp -= 20;
					}
				}
			}
		}

		if (this->ShootMode == 1) {
			this->timerValue = 800;
		}
		else {
			this->timerValue = 500;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			if (this->ShootMode == 1) {
				this->ShootMode = 0;
			}
			else if (this->ShootMode == 0) {
				this->ShootMode = 1;
			}
		}

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


						if (timer.getElapsedTime().asMilliseconds() > 500) {
							timer.restart();
							if (this->ShootMode == 0) {
								this->bullets.push_back(new Bullet(this->window, bulletState, posX + this->width / 2, this->posY));
							}
							else {
								this->bubbles.push_back(new Bubble(this->window, bulletState, posX + this->width / 2, this->posY));
							}
						}


					}
					else {
						if (this->state == LEFT) {
							this->bulletState = 1;

							if (timer.getElapsedTime().asMilliseconds() > 500) {
								timer.restart();
								if (this->ShootMode == 0) {
								this->bullets.push_back(new Bullet(this->window, bulletState, this->posX, posY + this->height / 2));
								}
								else {
									this->bubbles.push_back(new Bubble(this->window, bulletState, this->posX, posY + this->height / 2));
								}
							}
							anim.set("fightleft");
						}

						if (this->state == RIGHT) {
							this->bulletState = 2;
							if (timer.getElapsedTime().asMilliseconds() > 500) {
								timer.restart();
								if (this->ShootMode == 0) {
								this->bullets.push_back(new Bullet(this->window, bulletState, this->posX + width, posY + this->height / 2));
								}
								else {
									this->bubbles.push_back(new Bubble(this->window, bulletState, this->posX + width, posY + this->height / 2));
								}
							}
							anim.set("fightright");
						}


						if (this->state == JUMP) {
							if (this->rectY == 0) {
								if (timer.getElapsedTime().asMilliseconds() > 500) {
									timer.restart();
									if (this->ShootMode == 0) {
										this->bullets.push_back(new Bullet(this->window, bulletState, this->posX + width, posY + this->height / 2));
									}
									else {
										this->bubbles.push_back(new Bubble(this->window, bulletState, this->posX + width, posY + this->height / 2));
									}
								}
							}
							if (this->rectY >= 153) {
								if (timer.getElapsedTime().asMilliseconds() > 500) {
									timer.restart();
									if (this->ShootMode == 0) {
										this->bullets.push_back(new Bullet(this->window, bulletState, this->posX, posY + this->height / 2));
									}
									else {
										this->bubbles.push_back(new Bubble(this->window, bulletState, this->posX, posY + this->height / 2));
									}
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

		if (bubbles.size() != 0)
		{
			for (size_t i = 0; i < bubbles.size(); i++)
			{
				if (bubbles[i]->getAlive())
				{
					bubbles[i]->update(time);
				}
			}
		}

		if (this->posX + width > this->window->getSize().x)
		{
			this->posX += -0.5*time;
			this->posY += -0.5 *time;
		}

		if (this->posX < 0)
		{
			this->posX += 0.5  * time;
			this->posY += -0.5  * time;

		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->getAlive() == false)
			{
				bullets.erase(bullets.begin() + i);
			}
		}


		for (size_t i = 0; i < bubbles.size(); i++)
		{
			if (bubbles[i]->getAlive() == false)
			{
				bubbles.erase(bubbles.begin() + i);
			}
		}


	}

	// life---------------------------------
	this->str = std::to_string(this->hp);
	this->text.setString(str);
	this->text.setPosition(this->posX, this->posY-50);

	if (this->hp <= 0)
	{
		this->life = false;
		this->anim.set("death");
	}
	else
	{
		this->life = true;
		
	}



	//-------------------------------w-------

	anim.tick(time);
	

}


float Player::getPositionX()
{
	return this->posX;
}

float Player::getPositionY()
{
	return this->posY;
}

void Player::render(sf::RenderWindow * window) 
{
	window->draw(this->text);
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

if (bubbles.size() != 0) 
{

	for (size_t i = 0; i < bubbles.size(); i++)
		{
		bubbles[i]->render(window);
		}
	}
}


