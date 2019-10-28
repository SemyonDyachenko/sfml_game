#include "Bubble.h"
#include "../animation/AnimationManager.h"
#include "MapEditor.h"
#include "Enemy.h"
#include "objects/SFMLObject.h"
#include "Player.h"
#include "../GUI/PlayerHealtBar.h"

class PlayerHealtBar;
class MapEditor;
class AnimationManger;
class Player;
class Enemy;
class SFMLObject;

class Level
{
private:
	sf::RenderWindow * window;
protected:
	Player * player;
	std::vector<Enemy*> enemyes;
	std::vector<SFMLObject*> objects;

	sf::Texture sunT;
	sf::RectangleShape sun;

	sf::Texture skyT;
	sf::RectangleShape sky;

	sf::Texture skyT1;
	sf::RectangleShape sky1;

	sf::Texture skyT2;
	sf::RectangleShape sky2;

	sf::Texture skyT3;
	sf::RectangleShape sky3;

	sf::Vector2f skyPos1;
	sf::Vector2f skyPos2;


	sf::Texture skyT4;
	sf::RectangleShape sky4;
	sf::Texture skyT5;
	sf::RectangleShape sky5;

	sf::Texture skyT6;
	sf::RectangleShape sky6;




	sf::Texture playerTexture;

	sf::Texture tree;
	sf::Sprite treeSprite;

	sf::View levelView;


	//bar
	PlayerHealtBar bar;

	Music music;

	MapEditor * tilemap;

	bool start, end, pause;
	
	sf::Shader core_shader;

	void initShaders();
	void initTextures();
	void initVariables();
	void initView();
	void initPlayer();
	void initEnemyes();
	void initObject();
	void init();
public:
	Level(sf::RenderWindow & window,std::string map_filename,std::string back_filename);
	
	virtual ~Level();

	//void start();
	//void end();

	const bool & checkEnd() const;

	virtual void checkBackground(float time);

	virtual void updatePlayer(float time);
	virtual void updateEnemy(float time);
	virtual void updateObjects(float time);

	virtual void renderPlayer(sf::RenderWindow * window);
	virtual void renderEnemy(sf::RenderWindow * window);
	virtual void renderObjects(sf::RenderWindow * window);


	virtual void update(float time);
	virtual void render(sf::RenderWindow * window);
};

