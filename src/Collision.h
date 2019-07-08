#pragma once

#include "entities/Bullet.h"


namespace Collision {

	void collisionBallWithBullet(Bubble & bubble,Bullet & bullet)
	{
		if (bubble.getRect().intersects(bullet.getRect())) {
			bubble.setAlive(true);
			bullet.setAlive(true);
		}
	}


}