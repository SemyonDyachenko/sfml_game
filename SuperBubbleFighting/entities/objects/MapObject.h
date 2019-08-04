#ifndef MAPOBJECT_H
#define MAPOBJECT_H



class MapObject
{
private:
	sf::RectangleShape shape;
	float posX, posY;
	float width,height;

	std::string name;



public:
	MapObject();

	~MapObject();

	virtual void setPosition(const float x, const float y);
	virtual void setSize(const float width, const float height);

	const sf::FloatRect & getGlobalBounds() const;

	const std::string & getName() const;

	void update();
	void render(sf::RenderWindow * window);
};


#endif // ! MAPOBJECT_H