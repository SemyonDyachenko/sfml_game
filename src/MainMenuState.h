#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"


class MainMenuState : public State
{
private:
    sf::Texture backgroundTexture;
    sf::Font font;
    sf::RectangleShape background;
    std::map<std::string, Button*> buttons;


    //funcs
    void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();
public:
    MainMenuState(sf::RenderWindow * window, std::stack<State*>* states);
    virtual ~MainMenuState();


    void endState();

    //funcs
    void updateInput(const float& time);
    void updateButtons();
    void renderButtons(sf::RenderWindow * window);
    void update(const float& time);
    void render(sf::RenderWindow * window);
};


#endif
