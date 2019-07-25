#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "../entities/Enemy.h"
#include "../entities/MapEditor.h"



class GameState : public State
{
private:
	sf::View view;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

    Player *  player;

	//Enemy * enemy;
    sf::RenderWindow * window;



	MapEditor * tilemap;

 
    //funcs
	void initView();
	void initTileMap();
    void initTextures();
public:
    GameState(sf::RenderWindow * window, std::stack<State*>*states);
    virtual ~GameState();


    //funcs
    void endState();
    void updateInput(const float& time);
	void updateView(float time);
    void update(float time);
    void render(sf::RenderWindow *window);
};

#endif
