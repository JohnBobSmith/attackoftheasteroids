#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <string>

class Audio
{
    public:

        //Initialize our sounds
        Audio();

        //Our sounds
        sf::Sound bulletFire;
        sf::Sound enemyDeath;
        sf::Sound shieldImpact;
        sf::Sound laserFire;

        //Our music
        sf::Music mainMenuTheme;

    private:
        //One buffer per sound
        sf::SoundBuffer bulletFireBuffer;
        sf::SoundBuffer enemyDeathBuffer;
        sf::SoundBuffer shieldImpactBuffer;
        sf::SoundBuffer laserFireBuffer;
};

#endif // AUDIO_H



