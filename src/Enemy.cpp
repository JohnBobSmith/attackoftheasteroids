#include <SFML/Graphics.hpp>
#include "include/Enemy.h"
#include <iostream>

Enemy::Enemy()
{
	//Initialize variables
	isWaveSpawned = false;
	waveCounter = 1;

	//Initialize all of our enemies
	for (int i = 0; i < maxEnemies; ++i) {
		enemyVector.push_back(std::make_shared<EnemyObj>());
		if (!enemyVector[i]->asteroidTexture.loadFromFile("textures/easyAsteroid.png")) {
		    std::cerr << "Error: Missing texture file easyAsteroid.png\n";
		}
		enemyVector[i]->asteroidSprite.setTexture(enemyVector[i]->asteroidTexture);
		enemyVector[i]->velocityX = 0;
		enemyVector[i]->velocityY = 0;
		enemyVector[i]->positionX = -9999;
		enemyVector[i]->positionY = -9999;
		enemyVector[i]->isAlive = false;
		enemyVector[i]->isSpawned = false;
		enemyVector[i]->isCounted = false;
		enemyVector[i]->enemyVelocity = 30.0f;
		enemyVector[i]->maxEnemyHealth = 40.0f;
		enemyVector[i]->enemyHealth = enemyVector[i]->maxEnemyHealth;
		enemyVector[i]->originOffsetX = enemyVector[i]->asteroidTexture.getSize().x;
		enemyVector[i]->originOffsetY = enemyVector[i]->asteroidTexture.getSize().y;
		enemyVector[i]->asteroidSprite.setPosition(enemyVector[i]->positionX, enemyVector[i]->positionY);
		//Fade out time. Multiply by deltaTime in main() to equal the number of seconds.
		enemyVector[i]->fadeOutTime = sf::seconds(3.00);
		enemyVector[i]->isRendered = true;

        //Set the origin right away
        enemyVector[i]->asteroidSprite.setOrigin(enemyVector[i]->originOffsetX / 2, enemyVector[i]->originOffsetY / 2);
	}
}

bool Enemy::checkForWin(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector, int enemyCount)
{
    //Check for a win, where a win is defined as:
    //1) The enemy is not in play (dead)
    //2) There are no more living enemies remaining
    //      (did we kill ALL the enemies?)
    //3) The enemy was once in play, otherwise all idle enemies
    //      would be falsely counted

    //How many enemies are living?
    static int numberOfLiveEnemies = enemyCount;
    //For all possible enemies in play...
    for (int i = 0; i < maxEnemies; ++i) {
        //If the enemy is spawned...
        if (tempEnemyVector[i]->isSpawned) {
            //If the enemy is dead and not counted...
            if (!tempEnemyVector[i]->isAlive && !tempEnemyVector[i]->isCounted) {
                //Update the counter
                numberOfLiveEnemies -= 1;
                //Count the enemy only once
                tempEnemyVector[i]->isCounted = true;
            }
            if (numberOfLiveEnemies <= 0) {
                //Reset numberOfLiveEnemies.
                //If we are at the maximum amount of enemies,
                //do not add any further waves. Otherwise,
                //add an offset of 9 to the counter to
                //counter an otherwise impossible bug to fix
                // (adding 9 fixes it). This lets us win correctly.
                //MANUALLY LOOPING THROUGH THE WAVES IS UNSUPPORTED
                //AT THIS TIME...
                if (enemyCount == maxEnemies) {
                    numberOfLiveEnemies = enemyCount;
                } else {
                    numberOfLiveEnemies = enemyCount + 9;
                }

                for (int j = 0; j < maxEnemies; ++j) {
                    //No longer counted
                    tempEnemyVector[j]->isCounted = false;
                    //No longer spawned
                    tempEnemyVector[j]->isSpawned = false;
                }
                //We won, return true
                return true;
            }
        }
    }
    //We did not win, for any reason. Return false
    return false;
}

//Reset the asteroids positions, WIP wave-based system
void Enemy::resetEnemy(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector)
{
    //Position our enemies on the X axis
    for (int i = 0; i < localEnemyCount; ++i) {
        static int counter = 0;
        if (counter == 9) {
            counter = 0;
        }
        tempEnemyVector[i]->positionX = counter * 90;
        tempEnemyVector[i]->positionX += 32;
        counter += 1;
    }

    //Setup the y values properly
    for (int i = 0; i < localEnemyCount; ++i) {
        static int ammountToMove = 0;
        if (i == 0) {
            ammountToMove = 0;
        }
        if (i == 9) {
            ammountToMove = -100;
        }
        if (i == 18) {
            ammountToMove = -200;
        }
        if (i == 27) {
            ammountToMove = -300;
        }
        if (i == 36) {
            ammountToMove = -400;
        }
        if (i == 45) {
            ammountToMove = -500;
        }
        if (i == 54) {
            ammountToMove = -600;
        }
        if (i == 63) {
            ammountToMove = -700;
        }
        if (i == 72) {
            ammountToMove = -800;
        }
        tempEnemyVector[i]->positionY = ammountToMove;
    }
}

void Enemy::spawnEnemyWave(std::vector<std::shared_ptr<EnemyObj>> tempEnemyVector, int waveNumber)
{
    //Count our waves and add enemies accordingly
    switch (waveNumber)
    {
    case 0:
        localEnemyCount = 0;
        std::cout << "Warning! waveNumber in function Enemy::spawnEnemyWave must be >= 1!\n";
        break;
    case 1:
        localEnemyCount = 9;
        break;
    case 2:
        localEnemyCount = 18;
        break;
    case 3:
        localEnemyCount = 27;
        break;
    case 4:
        localEnemyCount = 36;
        break;
    case 5:
        localEnemyCount = 45;
        break;
    case 6:
        localEnemyCount = 54;
        break;
    case 7:
        localEnemyCount = 63;
        break;
    case 8:
        localEnemyCount = maxEnemies;
        break;
    default:
        std::cout << "Error: Default case triggered in function Enemy::spawnEnemyWave...\n";
        break;
    }

    //Spawn our enemies
    for (int i = 0; i < localEnemyCount; ++i) {
        tempEnemyVector[i]->isAlive = true;
        tempEnemyVector[i]->isSpawned = true;
    }

    //Position them
    resetEnemy(tempEnemyVector);
}
