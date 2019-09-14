#ifndef ASSETELEMENTSELECTOR_H
#define ASSETELEMENTSELECTOR_H

class AssetElementSelector
{
private:
	float width, height;
	float x, y;
	sf::RectangleShape shape;

	sf::Text label;
	sf::String str;
	
public:
	AssetElementSelector(float x,float y,float width,float height,sf::Font&font);
	~AssetElementSelector();


	void update();
	void render(sf::RenderWindow * window);
};


#endif 