#include "../../stdafx.h"
#include "TextureSelector.h"


void TextureSelector::initFonts()
{
	if (!this->font.loadFromFile("../res/fonts/font.ttf"))
		std::cout << "ERROR in TextureSelector.cpp, line 8 : don't load font from file " << "\n";
}

TextureSelector::TextureSelector(float x, float y, float width, float height,float gridSize,const sf::Texture* texture_sheet,std::string text)
{
	this->initFonts();
	this->gridSize = gridSize;
	this->active = false;
	this->isHide = false;

	this->bounds.setSize(sf::Vector2f(width, height));
	this->bounds.setPosition(x, y);
	this->bounds.setFillColor(sf::Color(50, 50, 50, 100));
	this->bounds.setOutlineThickness(1.f);
	this->bounds.setOutlineColor(sf::Color(255, 255, 255, 200));

	this->sheet.setTexture(*texture_sheet);
	this->sheet.setPosition(x, y);

	if (this->sheet.getGlobalBounds().width > this->bounds.getGlobalBounds().width)
	{
		this->sheet.setTextureRect(sf::IntRect(0, 0, this->bounds.getGlobalBounds().width, this->sheet.getGlobalBounds().height));
	}


	if (this->sheet.getGlobalBounds().height > this->bounds.getGlobalBounds().height)
	{
		this->sheet.setTextureRect(sf::IntRect(0, 0, this->sheet.getGlobalBounds().width, this->bounds.getGlobalBounds().height));
	}

	this->selector.setPosition(x, y);
	this->selector.setSize(sf::Vector2f(gridSize,gridSize));
	this->selector.setFillColor(sf::Color::Transparent);
	this->selector.setOutlineThickness(1.f);
	this->selector.setOutlineColor(sf::Color::Red);

	this->textureRect.width = static_cast<int>(gridSize);
	this->textureRect.height = static_cast<int>(gridSize);

}


TextureSelector::~TextureSelector()
{
	delete this->hider;
}

void TextureSelector::setHide(bool hide)
{
	this->isHide = hide;
}

const bool & TextureSelector::getHide() const
{
	return this->isHide;
}

const bool & TextureSelector::getActive() const
{
	return this->active;
}

const sf::IntRect & TextureSelector::getTextureRect() const
{
	return this->textureRect;
}

void TextureSelector::update(const sf::Vector2i& mousePosWindow)
{
	if (!this->isHide)
	{


		if (this->bounds.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow)))
			this->active = true;
		else
			this->active = false;


		if (this->active)
		{
			this->mousePosGrid.x = (mousePosWindow.x - static_cast<int>(this->bounds.getPosition().x)) / static_cast<unsigned>(this->gridSize);
			this->mousePosGrid.y = (mousePosWindow.y - static_cast<int>(this->bounds.getPosition().y)) / static_cast<unsigned>(this->gridSize);
			this->selector.setPosition(
				this->bounds.getPosition().x + this->mousePosGrid.x * this->gridSize,
				this->bounds.getPosition().y + this->mousePosGrid.y * this->gridSize
			);
		}

		//update texture rect
		this->textureRect.left = static_cast<int>(this->selector.getPosition().x - this->bounds.getPosition().x);
		this->textureRect.top = static_cast<int>(this->selector.getPosition().y - this->bounds.getPosition().y);
	}
}

void TextureSelector::render(sf::RenderWindow & window)
{
	

	if (!this->isHide)
	{
		window.draw(this->bounds);
		window.draw(this->sheet);
		if (this->active)
			window.draw(this->selector);
	}

	
}
