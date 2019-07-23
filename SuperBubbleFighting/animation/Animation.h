#ifndef ANIMATION_H
#define ANIMATION_H

#include "../TinyXML/tinyxml.h"
#include <SFML/Graphics.hpp>


using namespace sf;

class Animation
{
public:
	std::vector<IntRect> frames, frames_flip;
	float currentFrame, speed;
	bool loop, flip, isPlaying;   // loop показвает зациклена ли анимация. Например анимация взрыва должна проиграться один раз и остановиться, loop=false
	Sprite sprite;

	Animation();
	virtual ~Animation();

	void tick(float time);

};




#endif ANIMATION_H
