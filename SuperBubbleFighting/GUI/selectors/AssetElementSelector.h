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

	std::string	sourceFolder;

	bool isHide;
	
public:
	AssetElementSelector(float x,float y,float width,float height,sf::Font&font,std::string source_folder_path);
	~AssetElementSelector();


	void show();
	void hide();

	const bool& getHide() const;
	
	void update();
	void render(sf::RenderWindow * window);
};


#endif 