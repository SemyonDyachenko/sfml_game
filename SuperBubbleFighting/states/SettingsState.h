#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "State.h"
#include "../GUI/Button.h"
#include "../GUI/DropDown.h"


class SettingsState :
	public State
{
private:
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;
	std::map <std::string, DropDown*> dropDownLists;

	sf::Text optionsText;

	std::vector<sf::VideoMode> modes;

	//funcs
	void initVariables();
	void initFonts();
	void initButtons();
	void initGui();
	void initText();
public:
	SettingsState(sf::RenderWindow * window,std::stack<State*>* states);
	virtual ~SettingsState();


	void endState();

	//funcs
	void updateInput(const float& time);
	void updateButtons();
	void update(float time);
	void renderButtons(sf::RenderWindow * window);
	void render(sf::RenderWindow * window);
};



#endif // ! SETTINGS_STATE_H