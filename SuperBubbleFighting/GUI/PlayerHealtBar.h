#ifndef PLAYER_HEALTH_BAR_H
#define  PLAYER_HEALTH_BAR_H



class PlayerHealtBar
{
private:
	sf::Texture texture;
	sf::RectangleShape bar;
	sf::RectangleShape deathBar;
	int max;

	sf::Text text;
	sf::Font font;
	sf::String string;

	void initText();
	
public:
	PlayerHealtBar();
	virtual ~PlayerHealtBar();

	virtual void update(int healthcount);
	virtual void render(sf::RenderWindow * window);
};



#endif 
