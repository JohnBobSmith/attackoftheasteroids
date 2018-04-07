#include "include/Shield.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

Shield::Shield()
{
	for (int i = 0; i < maxShieldBlocks; ++i) {
		shieldVector.push_back(std::make_shared<ShieldObj>());
		if (!shieldVector[i]->shieldTexture.loadFromFile("../textures/shield.png")) {
			std::cout << "Error, missing shield texture ../textures/shield.png\n";
		}
    	shieldVector[i]->shieldSprite.setTexture(shieldVector[i]->shieldTexture);
    	shieldVector[i]->velocityX = 0;
    	shieldVector[i]->velocityY = 0;
    	shieldVector[i]->positionX = 0;
    	shieldVector[i]->positionY = 0;
    	shieldVector[i]->isShieldUp = false;
    }
}

sf::Vector2f Shield::calculateQuadratic(float n)
{
    sf::Vector2f tempVector;
    float y = 370 + (2.2 * (std::pow(n, 2)) / 800);
    float x = 390 + n;
    tempVector.x = x;
    tempVector.y = y;
    return tempVector;
}

void Shield::positionShieldBlocks()
{
    static int counter = 0;
    for (float i = -300; i <= 300; i += 10) {
        float x = calculateQuadratic(i).x;
        float y = calculateQuadratic(i).y;
        shieldVector[counter]->positionX = x;
        shieldVector[counter]->positionY = y;
        shieldVector[counter]->shieldSprite.setPosition(shieldVector[counter]->positionX,
                                                        shieldVector[counter]->positionY);
        //Do not overflow, because that would crash our game
        if (counter == maxShieldBlocks - 1) {
            break;
        }
        counter += 1;
    }
}
