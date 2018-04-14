#include "include/Audio.h"
#include <string>

Audio::Audio()
{
    bulletFireBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/bulletFire.wav");
    bulletFire.setBuffer(bulletFireBuffer);

    shieldImpactBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/shieldImpact.wav");
    shieldImpact.setBuffer(shieldImpactBuffer);

    laserFireBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/laserFire.wav");
    laserFire.setBuffer(laserFireBuffer);

    enemyDeathBuffer.loadFromFile(PREFIX "/share/attackoftheasteroids/audio/sfx/enemyDeath.wav");
    enemyDeath.setBuffer(enemyDeathBuffer);

    mainMenuTheme.openFromFile(PREFIX "/share/attackoftheasteroids/audio/music/mainMenuTheme.wav");
    mainMenuTheme.setLoop(true);
}
