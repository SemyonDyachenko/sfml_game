//
// Created by semyon on 19.06.19.
//

#ifndef CATCHONBUBBLE_PLAYER_H
#define CATCHONBUBBLE_PLAYER_H

#include "Entity.h"



class Player 
	: Entity
{
private:
	bool attack;

public:
    Player(float x,float y,sf::Texture& texture,MapEditor& level);
    virtual ~Player();

	const bool& checkLife() const;

    void movement(float time);
    void checkCollision(float Dx,float Dy);

	const sf::Vector2f& getPosition() const;



	void update(float time);

    void render(sf::RenderWindow * window);
};


#endif //CATCHONBUBBLE_PLAYER_H
