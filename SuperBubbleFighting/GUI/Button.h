#ifndef BUTTON_H
#define BUTTON_H



enum buttonStates
{
	BUTTON_IDLE = 0,
	BUTTON_HOVER,
	BUTTON_ACTIVE
};

class Button
{
private:
	short unsigned id;
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

	const std::string getText() const;
	const short unsigned & getID() const;

	void setText(std::string text);
	void setID(const short unsigned  id);

    const bool isPressed()  const;

    //funcs
    void update(const sf::Vector2f mousePos);
    void  render(sf::RenderWindow * window);
};

#endif
