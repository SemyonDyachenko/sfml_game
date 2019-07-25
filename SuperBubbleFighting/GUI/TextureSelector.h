#ifndef TEXTURE_SELECTOR_H
#define TEXTURE_SELECTOR_H

#include "Button.h"


class TextureSelector

{
private:

	float gridSize;
	bool active;
	bool isHide;
	Button* hider;


	sf::Font font;
	//std::string buttonText;

	sf::RectangleShape bounds;
	sf::Sprite sheet;
	sf::RectangleShape selector;

	sf::Vector2u mousePosGrid;
	sf::IntRect textureRect;

	void initFonts();

public:
	TextureSelector(float x,float y,float width,float height,float gridSize,const sf::Texture* texture_sheet, std::string text);
	virtual ~TextureSelector();


	void setHide(bool hide);
	const bool& getHide() const;

	const bool& getActive() const;
	const sf::IntRect & getTextureRect() const;

	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderWindow& window);         
};


#endif // !TEXTURE_SELECTOR_H