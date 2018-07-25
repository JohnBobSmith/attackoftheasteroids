#ifndef LASER_H
#define LASER_H

#include <SFML/Graphics.hpp>

class Laser
{
    public:
        Laser();

        //A boolean value to determine
        //when the laser is in use
        bool isLaserOn;

        //Damage the laser should do
        int laserDamage;

        //Our laser sprite
        sf::Sprite laserSprite;
        
        //Our time, since this is damage over time
        sf::Time tickTimer;
        sf::Time tickTimerInitial;

        //Grab the width/height
        int getWidth() { return laserTexture.getSize().x; }
        int getHeight() { return laserTexture.getSize().y; }

    private:
        sf::Texture laserTexture;
};

#endif // LASER_H
