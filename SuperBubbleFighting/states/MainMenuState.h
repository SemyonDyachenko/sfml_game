#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "../GUI/Button.h"
#include "EditorState.h"
#include "SettingsState.h"


class MainMenuState : public State
{
private:
    sf::Texture backgroundTexture;
    sf::Font font;
    sf::RectangleShape background;
    std::map<std::string, Button*> buttons;

	sf::RectangleShape cursor;
	sf::Texture textureCursor;

	Music theme;


	sf::Text text;

    //funcs
	void initCursor();
    void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();
	void initMusic();
public:
    MainMenuState(sf::RenderWindow * window, std::stack<State*>* states);
    virtual ~MainMenuState();


    void endState();

    //funcs
    void updateInput(const float& time);
    void updateButtons();
    void renderButtons(sf::RenderWindow * window);
    void update(float time);
    void render(sf::RenderWindow * window);
};


#endif
