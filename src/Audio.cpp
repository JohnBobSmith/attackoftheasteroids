#include "include/Audio.h"
#include <string>
#include <iostream>

Audio::Audio()
{
	if (!bulletFireBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/bulletFire.wav")) {
		std::cerr << "Warning: Missing audio file bulletFire.wav\n";
	}
    bulletFire.setBuffer(bulletFireBuffer);

    if (!shieldImpactBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/shieldImpact.wav")) {
    	std::cerr << "Warning: Missing audio file shieldImpact.wav\n";
    }
    shieldImpact.setBuffer(shieldImpactBuffer);

    if (!laserFireBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/laserFire.wav")) {
    	std::cerr << "Warning: Missing audio file laserFire.wav\n";
    }
    laserFire.setBuffer(laserFireBuffer);

	if !(enemyDeathBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/enemyDeath.wav")) {
		std::cerr << "Warning: Missing audio file enemyDeath.wav\n";
	}
    enemyDeath.setBuffer(enemyDeathBuffer);

    if (!mainMenuTheme.openFromFile(PREFIX "/share/attackoftheasteroids/audio/music/mainMenuTheme.wav")) {
    	std::cerr << "Warning: Missing audio file mainMenuTheme.wav\n";
    }
    mainMenuTheme.setLoop(true);
}
