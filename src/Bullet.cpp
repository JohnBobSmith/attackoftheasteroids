#ifdef M_PI
#undef M_PI
#endif // M_PI
#define M_PI 3.14159265
#include <SFML/Graphics.hpp>
#include "include/Bullet.h"
#include <iostream>
#include <cmath>

Bullet::Bullet()
{
	for (int i = 0; i < maxBullets; ++i) {
        bulletStorage.push_back(std::make_shared<BulletObj>());
        if (!bulletStorage[i]->bulletTexture.loadFromFile("textures/bullet.png")) {
        	std::cerr << "Warning: Missing texture file bullet.png\n";
        }
        bulletStorage[i]->bulletSprite.setTexture(bulletStorage[i]->bulletTexture);
		bulletStorage[i]->positionX = 0;
		bulletStorage[i]->positionY = 0;
		bulletStorage[i]->velocityX = 0;
		bulletStorage[i]->velocityY = 0;
		bulletStorage[i]->isActive = false;
		bulletStorage[i]->bulletVelocity = 500.0f;
		bulletStorage[i]->bulletDamage = 11;
		bulletStorage[i]->maxRateOfFire = sf::seconds(0.15);
		bulletStorage[i]->rateOfFire = bulletStorage[i]->maxRateOfFire;
   	}
}

void Bullet::shoot(Mouse &mouse, Audio &audio, sf::Time &deltaTime)
{
/*
    //The timer
    sf::Clock clock;
    static sf::Time startTime = sf::seconds(10000);
    startTime -= (sf::seconds(1) * deltaTime.asSeconds());
    std::cout << startTime.asSeconds() << std::endl;
*/

    //Current bullet being shot.
    //Used to shoot exactly one bullet at a time.
    static int currentBullet = 0;

    //Our rate of fire. Subtract 0.01f here always.
    //Do not change this value. Instead, adjust
    //bullet.maxRateOfFire to change fire rate
    bulletStorage[currentBullet]->rateOfFire -= (sf::seconds(1) * deltaTime.asSeconds());

    if (bulletStorage[currentBullet]->rateOfFire.asSeconds() <= 0) { //The our counter expired, so...
        //Fire our bullets one at a time
        currentBullet += 1;
        //If we run out of bullets, re-set to prevent a crash
        if (currentBullet >= getMaxBullets()) {
            currentBullet = 0;
        }
        //Allow for our bullet to be rendered, and set the trajectory
        //According to where the mouse was clicked.
        bulletStorage[currentBullet]->isActive = true;
        bulletStorage[currentBullet]->velocityX = bulletStorage[currentBullet]->bulletVelocity *
														(cos(mouse.getMouseAngle() * M_PI / 180));
    	bulletStorage[currentBullet]->velocityY = bulletStorage[currentBullet]->bulletVelocity *
														(sin(mouse.getMouseAngle() * M_PI / 180));

        //Play our firing sound
        audio.bulletFire.play();

        //Re-set the counter
        bulletStorage[currentBullet]->rateOfFire = bulletStorage[currentBullet]->maxRateOfFire;

    }
}
