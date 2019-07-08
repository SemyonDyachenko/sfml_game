#ifndef BUTTON_H
#define BUTTON_H

#include "../entities/Player.h"

enum buttonStates{
	BUTTON_IDLE = 0,
	BUTTON_HOVER,
	BUTTON_ACTIVE
};

class Button
{
private:
    short unsigned buttonState;

    sf::RectangleShape button;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor; // õîëîñòîé öâåò
    sf::Color hoverColor; // öâåò çàâèñàíèÿ ïðè íàâåäåíèè
    sf::Color activeColor; // àêòèâíûé öâåò



public:
    Button(float x, float y, float w, float h, sf::Font *font,
           std::string text,sf::Color idleColor,
           sf::Color hoverColor, sf::Color activeColor);
    ~Button();


    const bool isPressed()  const;

    //funcs
    void update(const sf::Vector2f mousePos);
    void  render(sf::RenderWindow * window);
};

#endif
