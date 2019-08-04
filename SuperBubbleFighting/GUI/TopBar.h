#ifndef TOPBAR_H
#define TOPBAR_H


#include "Button.h"

class TopBar
{
private:
	sf::Vector2f size;
	float posX, posY;
	sf::RectangleShape shape;

	sf::Font font;

	std::map<std::string, Button*> buttons;

	void initFonts();
	void initButtons();
public:
	TopBar(sf::RenderWindow * window, float x,float y);

	virtual ~TopBar();

	void update(sf::Vector2f mousePos);
	void render(sf::RenderWindow * window);
};

#endif // TOPBAR_H