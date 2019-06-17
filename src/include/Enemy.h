#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Enemy
{
    public:
    	struct EnemyObj
    	{
		    //The enemy sprite and texture
		    sf::Sprite asteroidSprite;
        	sf::Texture asteroidTexture;

        	//How long to fade out after death
        	sf::Time fadeOutTime;

        	//When we change the origin, store the offset.
        	int originOffsetX;
        	int originOffsetY;

		    //The enemies position and velocity
		    float velocityX;
		    float velocityY;
		    float positionX;
		    float positionY;

		    //Render the sprite?
		    bool isRendered;

		    //Is the enemy alive?
		    bool isAlive;

		    //Is an individual enemy spawned?
		    bool isSpawned;

		    //Is the enemy counted,
		    //in regards to win checking?
		    bool isCounted;

		    //Movement speed
		    float enemyVelocity;

		    //Max health of our enemies
		    float maxEnemyHealth;

		    //The enemies modify-able health
		    float enemyHealth;

		    //The opacity of a dead enemy
		    sf::Time opacity;
    	};

        //Setup our enemies automatically
        Enemy();

        //Expose the max number of enemies,
        //for initialization, collision, drawing only!
        int getMaxEnemies() { return maxEnemies; }

        //Get the local amount of enemies
        int getLocalEnemyCount() { return localEnemyCount; }

        //Did we win?
        bool checkForWin(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector, int enemyCount);

        //Spawn an enemy wave
        void spawnEnemyWave(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector, int waveNumber);

        //Reset and respawn our enemies
        void resetEnemy(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector);

	    //Did we spawn a wave of enemies?
	    bool isWaveSpawned;

	    //Keep track of which wave we are on
	    int waveCounter;

        //Store our enemies in an std::vector
        std::vector<std::shared_ptr<EnemyObj>> enemyVector;

    private:
        //For initializing, collision, and
        //drawing purposes only! Required
        //because said purposes require constant
        //values. Not intended to be changed.
        const int maxEnemies = 72;

        //How many enemies are playing/spawned
        //or should be spawn, those type of things.
        int localEnemyCount = 9;
};

#endif // ENEMY_H
