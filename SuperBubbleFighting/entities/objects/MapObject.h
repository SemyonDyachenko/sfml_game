#ifndef MAPOBJECT_H
#define MAPOBJECT_H



class MapObject
{
private:
	sf::RectangleShape shape;
	float posX, posY;
	float width,height;

	std::string name;

	sf::Font font;
	sf::Text text;


	void initFonts();
public:
	MapObject();
	MapObject(float x,float y,float gridSizeF,std::string name);

	virtual ~MapObject();

	sf::FloatRect rect;

	const sf::FloatRect & getGlobalBounds() const;

	const std::string & getName() const;

	const std::string getAssString() const;

	void update();
	void render(sf::RenderWindow & window);
};


#endif // ! MAPOBJECT_H