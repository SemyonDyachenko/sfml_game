#ifndef ENTITY_H
#define ENTITY_H


#include "MapEditor.h"
#include "../animation/AnimationManager.h"

class Entity
{
protected:
	float posX, posY,speed;
	bool life;
	unsigned hp;
	bool onGround;
	sf::Sprite sprite;
	AnimationManager animation;
public:
	Entity(float x, float y, sf::Texture& texture, MapEditor& level, std::string anim_file);
	virtual ~Entity();

	
	virtual const sf::Vector2f& getPosition() const;

	virtual void setPosition(const float x,const float y);

	virtual void update(float time) = 0;
	virtual void render(sf::RenderWindow *window) = 0;
};



#endif // ! ENTITY_H
