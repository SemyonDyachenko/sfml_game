#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
#include "../entities/Enemy.h"



class GameState : public State
{
private:
    Player *  player;
	std::vector<Enemy*> skeletons;
	//Enemy * enemy;
    sf::RenderWindow * window;
    sf::RectangleShape backgroundShape;    
	sf::Texture backTexture;
	sf::Texture groundTexture;
	 
	sf::RectangleShape ground;
	sf::RectangleShape  background;

	std::vector < std::vector < std::vector < Tile*> > > map;

	sf::Texture enemyTexture;
	

	
	sf::RectangleShape clouds;
	sf::Texture cloudsTexture;
	float cloudsPosX, cloudsPosY;

    sf::Music music;
    std::string musicpath;

	float viewSizeX,viewSizeY;

    //mouse
    sf::Vector2i pixelPos;
    sf::Vector2f pos;
    //funcs
	//void initAnimations();
    void initTextures();
public:
    GameState(sf::RenderWindow * window, std::stack<State*>*states);
    virtual ~GameState();


    //funcs
    void endState();
    void updateInput(const float& time);
    void update(float time);
    void render(sf::RenderWindow *window);
};

#endif
