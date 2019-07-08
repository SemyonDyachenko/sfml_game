#include "Button.h"



Button::Button(float x, float y, float w, float h, sf::Font * font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{

    this->buttonState = BUTTON_IDLE;

    this->button.setPosition(x, y);
    this->button.setSize(sf::Vector2f(w, h)); // width height


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(45);
    this->text.setPosition(
            this->button.getPosition().x + (this->button.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->button.getPosition().y + (this->button.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->button.setFillColor(this->idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
    if (this->buttonState == BUTTON_ACTIVE)
    {
        return true;
    }


    return false;
}

void Button::update(const sf::Vector2f mousePos)
{
    /*Îáíîâëåíèå  äëÿ ýôôåêòà êîäà íàæèìàåì êíîïêó è íàâîäèìñÿ */

    this->buttonState = BUTTON_IDLE;

    if (this->button.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BUTTON_HOVER;


        //íàæàòàÿ
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BUTTON_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
        case BUTTON_IDLE:
            this->button.setFillColor(this->idleColor);
            break;
        case BUTTON_HOVER:
            this->button.setFillColor(this->hoverColor);
            break;
        case BUTTON_ACTIVE:
            this->button.setFillColor(this->activeColor);
            break;

        default:
            this->button.setFillColor(sf::Color::Red);
            break;
    }

}

void Button::render(sf::RenderWindow * window)
{
    window->draw(this->button);
    window->draw(this->text);
}