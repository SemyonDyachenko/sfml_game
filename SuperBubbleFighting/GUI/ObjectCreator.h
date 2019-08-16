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

	float keytime;
	float keytimeMax;

	MapEditor * map;

	std::map<std::string, Button*> buttons;

public:
	ObjectCreator(sf::RenderWindow * window, MapEditor& map);
	virtual ~ObjectCreator();

	void setHide(bool hide);

	void show();
	void hide();

	const bool & getHide() const;

	const std::string& getName() const;

	const bool getKeyTime();

	const sf::Vector2f& getPosition() const;

	virtual void updateKeyTime(float time);

	void update(sf::Vector2f mousePos, float time);


	void render(sf::RenderWindow * window);
};


#endif // OBJECTCREATOR_H