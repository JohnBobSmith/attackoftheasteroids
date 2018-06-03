#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>

class Powerup
{
	public:
		Powerup();
		
		sf::Sprite puSprite;
		sf::Texture puTexture;
		sf::vector2f position;
		float velocity;
};

#endif //POWERUP_H
