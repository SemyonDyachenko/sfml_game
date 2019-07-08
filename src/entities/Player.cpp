//
// Created by semyon on 19.06.19.
//

#include "Player.h"
#include "../Collision.h"




//shootMode
// 1- bubble
// 0 - bullet

Player::Player(sf::RenderWindow *window,std::string path,float x,float y) {
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

}

Player::~Player() {
	
}

void Player::setView(float x, float y) {
this->view.setCenter(x+20,y);
}



void Player::movement(float time) {
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		anim.set("stay");
	}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X) > 1)) {
	this->rectX = 150;
	this->rectY = 0;
    this->state = RIGHT; this->speed = 0.1f;
	anim.set("right");
  //  this->setView(posX,posY);
}
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < 0)) {
	this->rectX = 150;
	this->rectY = 153;
    this->state = LEFT; this->speed = 0.1f;
   // this->setView(posX,posY);
	anim.set("left");
}
if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (sf::Joystick::isButtonPressed(0, 5))) && (playerOnGround)) {
    this->state = JUMP;
    this->dy = -0.4f;
    this->playerOnGround = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		anim.set("jumpleft");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		anim.set("jumpright");
	}
}

/*if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
{
	this->speed = 0;
	this->currentFrameTime += 0.005 * time;
	if (currentFrameTime > 3) currentFrameTime -= 3;
	this->sprite.setTextureRect(sf::IntRect(96 * int(currentFrameTime), 94, 83, 83));
}
*/ 
 // выше анимация на случай кода персонаж просто стоит ,потом нарисую 

}



void Player::checkCollision(float Dy,float Dx, sf::RectangleShape*object) {
	if (sf::FloatRect(posX, posY, width, height).intersects(sf::FloatRect(object->getPosition().x,object->getPosition().y,object->getSize().x,object->getSize().y)))
	{
		if (Dy > 0) { this->posY = object->getPosition().y - height; this->dy = 0; this->playerOnGround = true; }
   }
    //
}



void Player::update(float time, sf::RectangleShape*object) {
	movement(time);
	switch (state) {

	case STAY:break;
	case LEFT:this->dx = -speed; break;
	case RIGHT:this->dx = speed; break;
	case JUMP:break;
	}

	this->posX += dx * time;
	checkCollision(dy, dx, object);
	this->posY += dy * time;
	checkCollision(dy, 0, object);
	this->speed = 0;       
	this->sprite.setPosition(posX, posY);
	this->dy = dy + 0.0014*time;
	checkCollision(dx, dy, object);





	if (this->ShootMode ==1) {
		this->timerValue = 800;
	}
	else {
		this->timerValue = 500;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Joystick::isButtonPressed(0, 4)) {
		if (this->ShootMode == 1) {
			this->ShootMode = 0;
		}
		else if (this->ShootMode == 0) {
			this->ShootMode = 1;
		}
	}

	if (playerOnGround)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Joystick::isButtonPressed(0, 6)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) < 0)) {
				this->bulletState = 3;

				
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
		}

	}

	
	if (bullets.size() != 0) {

		for (size_t i = 0; i < bullets.size(); i++) {
			if (bullets[i]->getAlive()) {
				bullets[i]->update(time);
			}
		}
	}

	if (bubbles .size() != 0) {
		for (size_t i = 0; i < bubbles.size(); i++) {
			if (bubbles[i]->getAlive()) {
				bubbles[i]->update(time);
			}
		}
	}

    if(this->posX+width > this->view.getSize().x) {

            this->posX += -0.5*time;
            this->posY += -0.5 *time;

    }

    if(this->posX < 0) {

            this->posX += 0.5  *time;
            this->posY += -0.5  *time;

    }

	for (size_t i = 0; i < bullets.size(); i++) {
		if (bullets[i]->getAlive() == false) {
			bullets.erase(bullets.begin() + i);
		}
	}
	

	for (size_t i = 0; i < bubbles.size(); i++) {
		if (bubbles[i]->getAlive() == false) {
			bubbles.erase(bubbles.begin() + i);
		}
	}



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

void Player::render(sf::RenderWindow * window) {
	anim.draw(*window,this->posX,this->posY);

if (bullets.size() != 0) {
	for (size_t i = 0; i < bullets.size(); i++) {
		if (bullets[i]->getAlive()== true) {
		bullets[i]->render(window);
		}
	}
}

if (bubbles.size() != 0) {

	for (size_t i = 0; i < bubbles.size(); i++) {
	
			bubbles[i]->render(window);
		
	}
}


}


