#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H


#include "Animation.h"


class AnimationManager
{

public:
	std::string currentAnim;
	std::map<std::string, Animation> animList;

	AnimationManager();

	~AnimationManager();

	//создание анимаций вручную
	void create(std::string name, Texture &texture, int x, int y, int w, int h, int count, float speed, int step = 0, bool Loop = true);


	//загрузка из файла XML
	void loadFromXML(std::string fileName, Texture &t);

	

	void set(std::string name);

	void draw(RenderWindow &window, int x = 0, int y = 0);

	void flip(bool b = 1);

	void tick(float time);

	void pause();

	void play();

	void play(std::string name);

	bool isPlaying();

	float getH();

	float getW();

	float getPositionX();
	float getPositionY();

};



#endif