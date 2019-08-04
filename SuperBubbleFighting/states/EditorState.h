#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "../GUI/Button.h"
#include "../entities/MapEditor.h"
#include "../GUI/TextureSelector.h"
#include "../GUI/ObjectCreator.h"

class EditorState :
	public State
{
private:
	sf::Font font;
	std::string string;
	sf::Text text;

	ObjectCreator * objCreator;
	

	std::map<std::string, Button*> buttons;

	sf::RenderWindow * window;

	MapEditor * map;
	
	sf::View editorView;
	float cameraSpeed;

	sf::RectangleShape selectorRect;
	
	sf::RectangleShape mouseSelector;
	float mouseSelectorPosX, mouseSelectorPosY;

	sf::Vector2i pixelPos;
	sf::Vector2f pos;

	bool collision;
	short type;



	TextureSelector *textureSelector;
	
	sf::Texture tileset;


	sf::IntRect textureRect;

	void initView();
	void initTextures();
	void initGui();
	void initVariables();
	void initSelector();

public:
	EditorState(sf::RenderWindow *window,std::stack<State*>* states);
	virtual ~EditorState();

	void endState();
	void updateInput(const float& time);
	void updateView(float time);
	void update(float time);
	void render(sf::RenderWindow * window);
};



#endif // ! EDITORSTATE_H