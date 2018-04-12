#include "include/Audio.h"
#include <string>

Audio::Audio()
{
    bulletFireBuffer.loadFromFile("/usr/share/attackoftheasteroids/audio/sfx/bulletFire.wav");
    bulletFire.setBuffer(bulletFireBuffer);

    shieldImpactBuffer.loadFromFile("/usr/share/attackoftheasteroids/audio/sfx/shieldImpact.wav");
    shieldImpact.setBuffer(shieldImpactBuffer);

    laserFireBuffer.loadFromFile("/usr/share/attackoftheasteroids/audio/sfx/laserFire.wav");
    laserFire.setBuffer(laserFireBuffer);

    enemyDeathBuffer.loadFromFile("/usr/share/attackoftheasteroids/audio/sfx/enemyDeath.wav");
    enemyDeath.setBuffer(enemyDeathBuffer);

    mainMenuTheme.openFromFile("/usr/share/attackoftheasteroids/audio/music/mainMenuTheme.wav");
    mainMenuTheme.setLoop(true);
}
