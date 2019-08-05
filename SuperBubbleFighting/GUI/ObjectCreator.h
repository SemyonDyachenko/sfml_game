#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include "Button.h"

class ObjectCreator
{
private:
	sf::RenderWindow * window;
	sf::Font font;
	sf::Text text;
	std::string name;

	sf::RectangleShape creationWindow;
	sf::RectangleShape enterField;

	bool isHide;

	

	std::map<std::string, Button*> buttons;

public:
	ObjectCreator(sf::RenderWindow * window);
	virtual ~ObjectCreator();

	void setHide(bool hide);

	const bool & getHide() const;


	void update(sf::Vector2f mousePos);

	void render(sf::RenderWindow * window);
};


#endif // OBJECTCREATOR_H