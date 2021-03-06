#include "include/Laser.h"
#include <iostream>

Laser::Laser()
{
    isLaserOn = false;
    laserDamage = 0.025;
    laserDamageToPlayer = 2;
    tickTimerInitial = sf::seconds(0.1);
    tickTimer = tickTimerInitial;
    if (!laserTexture.loadFromFile("textures/laser.png")) {
        std::cerr << "Error: Missing texture file laser.png\n";
    }
    laserSprite.setTexture(laserTexture);
    //Position the laser at the bottom, because it shoots
    //from the sides of our moon hut
    laserSprite.setPosition(0, 550);
}
