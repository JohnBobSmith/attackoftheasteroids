#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/UI.h"

UI::UI()
{
    //Load each texture
    if (!startButtonTexture.loadFromFile("/usr/share/attackoftheasteroids/textures/ui/start.png")) {
        std::cout << "Missing start button texture!\n";
    }
    startButton.setTexture(startButtonTexture);

    if (!quitButtonTexture.loadFromFile("/usr/share/attackoftheasteroids/textures/ui/quit.png")) {
        std::cout << "Missing quit button texture!\n";
    }
    quitButton.setTexture(quitButtonTexture);

    if (!helpButtonTexture.loadFromFile("/usr/share/attackoftheasteroids/textures/ui/help.png")) {
        std::cout << "Missing help button texture!\n";
    }
    helpButton.setTexture(helpButtonTexture);

    if (!helpPageTexture.loadFromFile("/usr/share/attackoftheasteroids/textures/ui/helppage.png")) {
        std::cout << "Missing help page texture!\n";
    }
    helpPage.setTexture(helpPageTexture);

    //Set the positions
    startButton.setPosition(startButtonX, startButtonY);
    quitButton.setPosition(quitButtonX, quitButtonY);
    helpButton.setPosition(helpButtonX, helpButtonY);
    helpPage.setPosition(helpPageX, helpPageY);
}
