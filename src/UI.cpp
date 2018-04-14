#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/UI.h"

UI::UI()
{
    //Load each texture
    if (!startButtonTexture.loadFromFile(PREFIX "/share/attackoftheasteroids/textures/ui/start.png")) {
        std::cerr << "Missing start button texture!\n";
    }
    startButton.setTexture(startButtonTexture);

    if (!quitButtonTexture.loadFromFile(PREFIX "/share/attackoftheasteroids/textures/ui/quit.png")) {
        std::cerr << "Missing quit button texture!\n";
    }
    quitButton.setTexture(quitButtonTexture);

    if (!helpButtonTexture.loadFromFile(PREFIX "/share/attackoftheasteroids/textures/ui/help.png")) {
        std::cerr << "Missing help button texture!\n";
    }
    helpButton.setTexture(helpButtonTexture);

    if (!helpPageTexture.loadFromFile(PREFIX "/share/attackoftheasteroids/textures/ui/helppage.png")) {
        std::cerr << "Missing help page texture!\n";
    }
    helpPage.setTexture(helpPageTexture);

    //Set the positions
    startButton.setPosition(startButtonX, startButtonY);
    quitButton.setPosition(quitButtonX, quitButtonY);
    helpButton.setPosition(helpButtonX, helpButtonY);
    helpPage.setPosition(helpPageX, helpPageY);
}
