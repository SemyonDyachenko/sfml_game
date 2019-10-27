#ifndef PLAYER_HEALTH_BAR_H
#define  PLAYER_HEALTH_BAR_H



class PlayerHealtBar
{
private:
	sf::Texture texture;
	sf::RectangleShape bar;
	sf::RectangleShape deathBar;
	int max;
public:
	PlayerHealtBar();
	virtual ~PlayerHealtBar();

	virtual void update(int healthcount);
	virtual void render(sf::RenderWindow * window);
};



#endif 
