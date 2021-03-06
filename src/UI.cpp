#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/UI.h"

UI::UI()
{
    //Load each texture
    if (!startButtonTexture.loadFromFile("textures/ui/start.png")) {
        std::cerr << "Warning: Missing texture file start.png\n";
    }
    startButton.setTexture(startButtonTexture);

    if (!quitButtonTexture.loadFromFile("textures/ui/quit.png")) {
        std::cerr << "Warning: Missing texture file quit.png\n";
    }
    quitButton.setTexture(quitButtonTexture);

    if (!helpButtonTexture.loadFromFile("textures/ui/help.png")) {
        std::cerr << "Warning: Missing texture file help.png\n";
    }
    helpButton.setTexture(helpButtonTexture);

    if (!helpPageTexture.loadFromFile("textures/ui/helppage.png")) {
        std::cerr << "Warning: Missing texture file helppage.png\n";
    }
    helpPage.setTexture(helpPageTexture);

    //Set the positions
    startButton.setPosition(startButtonX, startButtonY);
    quitButton.setPosition(quitButtonX, quitButtonY);
    helpButton.setPosition(helpButtonX, helpButtonY);
    helpPage.setPosition(helpPageX, helpPageY);
}
