#ifndef DROPDOWN_H
#define DROPDOWN_H

#include "Button.h"

class DropDown
{
private:
	std::map<std::string, Button*> buttons;

	sf::Vector2f size;

	float posX, posY;

	bool isDrop;

public:
	DropDown(std::map<std::string, Button*> buttons);

	virtual ~DropDown();

	void setDrop(bool drop);

	void update(sf::Vector2f mousePos);

	void renderButtons(sf::RenderWindow * window);
	void render(sf::RenderWindow * window);
};

#endif // ! DROPDOWN_H

