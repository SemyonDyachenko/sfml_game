#ifndef DROPDOWN_H
#define DROPDOWN_H

#include "Button.h"

class DropDown
{
private:
	float keytime;
	float keytimeMax;

	sf::Font& font;
	Button* activeElement;
	std::vector<Button*> list;
	bool showList;


public:
	DropDown(float x, float y, float width, float height,sf::Font& font, std::string list[],unsigned nrOfElements, unsigned default_index = 0);

	~DropDown();

	const unsigned short& getActiveElementId() const;

	const bool getKeytime();

	void updateKeytime(float time);

	void update(sf::Vector2f mousePos,float time);

	void render(sf::RenderWindow * window);
};

#endif // ! DROPDOWN_H

