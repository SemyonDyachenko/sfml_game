#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include "Button.h"
#include "../entities/MapEditor.h"

class MapEditor;

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

	MapEditor * map;

	std::map<std::string, Button*> buttons;

public:
	ObjectCreator(sf::RenderWindow * window, MapEditor& map);
	virtual ~ObjectCreator();

	void setHide(bool hide);

	const bool & getHide() const;

	const std::string& getName() const;

	const sf::Vector2f& getPosition() const;

	void update(sf::Vector2f mousePos);

	void render(sf::RenderWindow * window);
};


#endif // OBJECTCREATOR_H