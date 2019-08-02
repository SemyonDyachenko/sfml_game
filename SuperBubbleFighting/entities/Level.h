#include "Bubble.h"
#include "../animation/AnimationManager.h"
#include "MapEditor.h"
#include "Enemy.h"
#include "objects/SFMLObject.h"


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

	sf::Texture backgroundTexture;
	sf::Sprite background;

	sf::View levelView;

	MapEditor * tilemap;

	bool start, end;
	
	void initTextures();
	void initVariables();
	void initView();
	void init();
public:
	Level(sf::RenderWindow & window,std::string map_filename,std::string back_filename);
	
	virtual ~Level();

	virtual void start();
	virtual void end();

	const bool & checkEnd() const;

	virtual void updatePlayer(float time);
	virtual void updateEnemy(float time);
	virtual void updateObjects(float time);

	virtual void renderPlayer(sf::RenderWindow * window);
	virtual void renderEnemy(sf::RenderWindow * window);
	virtual void renderObjects(sf::RenderWindow * window);

	virtual void update(float time);
	virtual void render(sf::RenderWindow * window);
};

