#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Mouse.h"

class Bullet
{
    public:
    	struct BulletObj 
    	{
		    //Every bullet must have a sprite
		    sf::Sprite bulletSprite;
		    
		    //Every bullet must have a texture
		    sf::Texture bulletTexture;
		    
		    //Every bullet must have a bounding box
		    sf::RectangleShape bbox;

		    //The position of our bullet
		    float positionX;
		    float positionY;
		 	
		 	//The velocity of the bullet
		 	float velocityX;
		 	float velocityY;

		    //do we render/interact with this bullet?
		    bool isActive;

		    //How fast are our bullets?
		    float bulletVelocity;

		    //Every bullet does damage
		    int bulletDamage;

		    //Cap our rate of fire
		    //Change this to change the rate of fire
		    float maxRateOfFire;

		    //Our working rate of fire which 
		    //we can do stuff to
		    float rateOfFire;
		};
		
        //Set our bullets up automatically
        Bullet();
        
        //Shoot a bullet
        void shoot(Mouse &mouse);

        //Expose the maximum amount of bullets allowed
        int getMaxBullets() { return maxBullets; };
        
        //Our bullet storage vector. 
        std::vector<std::shared_ptr<BulletObj>> bulletStorage;

    private:
        //Give our for-loops a boundary, and
        //prevent an excessive amount of bullets
        //from accumulating. Not intended to be changed
        //by anything, hence private and const.
        const int maxBullets = 200;
};

#endif // BULLET_H
