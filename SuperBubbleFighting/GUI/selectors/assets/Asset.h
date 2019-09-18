#ifndef ASSET_H
#define ASSET_H



class Asset
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::RectangleShape shape;

	float width, height, x, y;
	
	std::string path;

	bool isSelect;

	
	
	void init();
public:
	Asset(float x, float y,std::string path);
	virtual ~Asset();

	const bool& checkSelect() const;
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getSize() const;

	virtual void update();
	
	void render(sf::RenderWindow&window);
};

#endif