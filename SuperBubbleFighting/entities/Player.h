//
// Created by semyon on 19.06.19.
//

#ifndef CATCHONBUBBLE_PLAYER_H
#define CATCHONBUBBLE_PLAYER_H

#include "Bullet.h"

class Player {
protected:
    sf::RenderWindow * window;
    float posX,posY,dx,dy;
    float speed;
    enum MovementDirection {
        STAY,
        LEFT,
        RIGHT,
        JUMP
    };
    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texture;
    std::string path;
    MovementDirection state;
    float currentFrameTime;
    float width,height,rectX,rectY;
	int bulletState;
    bool playerOnGround;
	sf::Clock timer;
	std::vector<Bullet*> bullets;
	std::vector<Bubble*> bubbles;
	float sleep;
	float timerValue;
	bool ShootMode;
public:
    sf::View view;
    Player(sf::RenderWindow *window,std::string path,float x,float y);
    virtual ~Player();

    void setView(float x,float y);
    void movement(float time);
    void checkCollision(float Dy, float Dx, sf::RectangleShape *object);
	void update(float time, sf::RectangleShape *object);
	float getPositionX();
	float getPositionY();
    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_PLAYER_H
