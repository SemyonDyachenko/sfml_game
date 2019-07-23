#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "../GUI/Button.h"
#include "../entities/MapEditor.h"
#include "../GUI/TextureSelector.h"

class EditorState :
	public State
{
private:
	sf::Font font;
	std::string string;
	sf::Text text;

	std::map<std::string, Button*> buttons;

	sf::RenderWindow * window;

	MapEditor * map;
	
	sf::RectangleShape selectorRect;
	
	sf::RectangleShape mouseSelector;
	float mouseSelectorPosX, mouseSelectorPosY;

	sf::Vector2i pixelPos;
	sf::Vector2f pos;
	sf::Vector2u mousePosGrid;

	TextureSelector *textureSelector;
	
	sf::Texture tileset;


	sf::IntRect textureRect;

	void initTextures();
	void initGui();
	void initVariables();
	void initBackground();
	void initFonts();
	void initSelector();

public:
	EditorState(sf::RenderWindow *window,std::stack<State*>* states);
	virtual ~EditorState();

	void endState();
	void updateInput(const float& time);
	void update(float time);
	void render(sf::RenderWindow * window);
};



#endif // ! EDITORSTATE_H