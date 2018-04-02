#include <SFML/Graphics.hpp>
#include "include/Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	for (int i = 0; i < maxBullets; ++i) {
        bulletStorage.push_back(std::make_shared<BulletObj>());
        if (!bulletStorage[i]->bulletTexture.loadFromFile("../textures/bullet.png")) {
        	std::cerr << "Warning: Missing texture file ../textures/bullet.png\n";
        }
        bulletStorage[i]->bulletSprite.setTexture(bulletStorage[i]->bulletTexture);
		bulletStorage[i]->positionX = 0;
		bulletStorage[i]->positionY = 0;
		bulletStorage[i]->velocityX = 0;
		bulletStorage[i]->velocityY = 0;
		bulletStorage[i]->isActive = false;
		bulletStorage[i]->bulletVelocity = 75.0f;
		bulletStorage[i]->bulletDamage = 12;
		bulletStorage[i]->maxRateOfFire = 0.45;
		bulletStorage[i]->rateOfFire = bulletStorage[i]->maxRateOfFire;
   	}
}

void Bullet::shoot()
{
    //Current bullet being shot.
    //Used to shoot exactly one bullet at a time.
    static int currentBullet = 0;
    
    //Our rate of fire. Subtract 0.01f here always.
    //Do not change this value. Instead, adjust
    //bullet.maxRateOfFire to change fire rate
    bullet.bulletStorage[currentBullet]->rateOfFire -= 0.01f;

    if (bullet.bulletStorage[currentBullet]->rateOfFire <= 0.0f) { //The our counter expired, so...
        //Fire our bullets one at a time
        currentBullet += 1;
        //If we run out of bullets, re-set to prevent a crash
        if (currentBullet >= bullet.getMaxBullets()) {
            currentBullet = 0;
        }
        //Allow for our bullet to be rendered, and set the trajectory
        //According to where the mouse was clicked.
        bullet.bulletStorage[currentBullet]->isActive = true;
        bullet.bulletStorage[currentBullet]->velocityX = bullet.bulletStorage[currentBullet]->bulletVelocity * 
        																		(cos(mouseAngle * pi / 180));
        bullet.bulletStorage[currentBullet]->velocityY = bullet.bulletStorage[currentBullet]->bulletVelocity *
        																		 (sin(mouseAngle * pi / 180));

        //Play our firing sound
        //audio.bulletFire.play();

        //Re-set the counter
        bullet.bulletStorage[currentBullet]->rateOfFire = bullet.bulletStorage[currentBullet]->maxRateOfFire;
    
    }
}
