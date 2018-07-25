#include "include/Player.h"
#include <iostream>

Player::Player()
{
    if(!playerTexture.loadFromFile(PREFIX "/share/attackoftheasteroids/textures/moonbase.png")) {
        std::cerr << "Error: Missing texture file moonbase.png\n";
    }
    playerSprite.setTexture(playerTexture);

    //Set the position of the player to the bottom center of the screen
    playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    playerSprite.setPosition(800 / 2, 600 - playerTexture.getSize().y / 2);

    //Set size, color, and position of our health bar
    healthBar.setSize(sf::Vector2f(20, 50));
    //Starts with full health
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setPosition(800 / 2 + 15, 600);
    
    //Set the background for our health bar
    healthBarBackground.setSize(sf::Vector2f(40, 80));
    healthBarBackground.setFillColor(sf::Color::Black);
    healthBarBackground.setPosition(700 / 2 + 31, 540);
}
