#ifndef SHIELD_H
#define SHIELD_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Shield
{
    public:
    	struct ShieldObj
    	{
		    //Sprite and texture
		    sf::Sprite shieldSprite;
            sf::Texture shieldTexture;

		    //Velocities and positions
		    float velocityX;
		    float velocityY;
		    float positionX;
		    float positionY;

		    //Is an individual shield block running?
		    bool isShieldUp;
    	};

        //Automaticaly setup our shield blocks
        Shield();

       	//Calculate a quadradic equation used for
       	//making our shields curve uniformly
        sf::Vector2f calculateQuadratic(float n);

        //Position our shield blocks
        void positionShieldBlocks();

        //Return the max amount of shield segments
        int getMaxShieldBlocks() { return maxShieldBlocks; }

        //Our shield vector storage
        std::vector<std::shared_ptr<ShieldObj>> shieldVector;

    private:
        //Number of shield segments
        const int maxShieldBlocks = 60;
};

#endif // SHIELD_H
