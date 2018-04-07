#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "include/Player.h"
#include "include/Bullet.h"
#include "include/Enemy.h"
#include "include/Shield.h"
#include "include/CollisionBox.h"
#include "include/UI.h"
#include "include/Audio.h"
#include "include/Laser.h"
#include "include/Mouse.h"

int main()
{
    //Frame rate limiter
    const float timeStep = 1/60.0f;

    //Our window and event union
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_WIDTH = 800;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Attack of the Asteroids");
    sf::Event event;

    //Our square font
    sf::Font blockFont;
    blockFont.loadFromFile("../fonts/ehsmb.ttf");

    //Our game over text
    sf::Text gameOverText;
    gameOverText.setFont(blockFont);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(110);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Regular);
    //Center this text
    gameOverText.setPosition(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 3);

    //Our space to start text or prompt
    sf::Text spaceTostartText;
    spaceTostartText.setFont(blockFont);
    spaceTostartText.setString("space bar to start");
    spaceTostartText.setCharacterSize(55);
    spaceTostartText.setFillColor(sf::Color::Yellow);
    spaceTostartText.setStyle(sf::Text::Regular);
    //Position this text just below our win/loss text
    spaceTostartText.setPosition(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 2);

    //Our victory text
    sf::Text winText;
    winText.setFont(blockFont);
    winText.setString("You WIN!!");
    winText.setCharacterSize(110);
    winText.setFillColor(sf::Color::Green);
    winText.setStyle(sf::Text::Regular);
    //Center our text
    winText.setPosition(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 3);

    //Our background image
    sf::Sprite background;
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../textures/bg.png");
    background.setTexture(backgroundTexture);

    //The laser
    Laser laser;
    
    //Our mouse
    Mouse mouse;

    //Our collision detection object
    CollisionBox collisionbox;

    //Our user interface object
    UI ui;

    //The player
    Player player;

    //Audio
    Audio audio;
    //Play music immediately
    audio.mainMenuTheme.play();

    //Our bullet object
    Bullet bullet;
    
    //Our shield object
    Shield shield;
    shield.positionShieldBlocks();

    //Enemy object and pointers
    //CLEAN THIS UP
    Enemy enemy;
    std::vector<Enemy*> enemyVector;
    for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
        enemyVector.push_back(new Enemy());
    }

	/*
    //Shield object and pointers
    //CLEAN THIS UP TOO!
    Shield shield;
    std::vector<Shield*> shieldVector;
    for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
        shieldVector.push_back(new Shield());
        //Enable the shield
        shieldVector[i]->isShieldUp = true;
    }
	//*/

    /* * * * MAIN LOOP * * * */
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                //We pressed the titlebar's X button
                window.close(); //Quit.
            }
            //Update the mouse position
            mouse.update(event);
            //If we release right mouse, turn off laser
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    laser.isLaserOn = false;
                }
            }
        } //End event loop

        //Return to the main menu at any time when we press escape.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            ui.isMainMenu = true;
        }

        //Process these events only if we are playing
        if (ui.isPlaying) {
            //Mouse down event. Shoot with left mouse
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				bullet.shoot(mouse);
			}

            //Mouse right event. Fire our laser.
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                laser.isLaserOn = true;
            }
        }

        //END OF EVENTS, START OF GAME LOGIC

        //Handle our music here as this seems
        //to be the only place it works...
        //If we are not in the main menu, mute music
        if (!ui.isMainMenu) {
            audio.mainMenuTheme.setVolume(50);
        } else {
            audio.mainMenuTheme.setVolume(75);
        }

        //Running our actual game
        if (ui.isPlaying) {
            //Enemy wave spawning logic
            if (!enemy.isWaveSpawned) {
                //Spawn 1 wave at a time
                static int counter = 1;
                //Because our counter variable is not
                //A constant expression, we must use
                //if statements instead of case, or
                //we get a compiler error.
                if (counter == 1 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 1);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 2 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 2);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 3 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 3);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 4 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 4);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 5 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 5);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 6 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 6);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 7 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 7);
                    counter += 1;
                    enemy.isWaveSpawned = true;
                }
                if (counter == 8 && !enemy.isWaveSpawned) {
                    enemy.spawnEnemyWave(enemyVector, 8);
                    counter = 8; //Do not add any more waves
                    enemy.isWaveSpawned = true;
                }
            }
            //Win checking
            //This is done right away, so that if this
            //returns false, checking for a loss still occurs
            if (enemy.checkForWin(enemyVector, enemy.getLocalEnemyCount())) {
                //We won, :D
                ui.isWin = true;
                ui.isPlaying = false;
            }

            //If the laser is on, drain the player health
            //Also play the sound
            if (laser.isLaserOn) {
                player.playerHealth -= laser.laserDamage;
                audio.laserFire.play();
            }

            //Check the status of our health bar
            //Starts off as green by default, we
            //don't need to check that here.
            if (player.playerHealth <= 70) {
                //Yellow health
                player.healthBar.setFillColor(sf::Color::Yellow);
            }
            if (player.playerHealth <= 30) {
                //red health
                player.healthBar.setFillColor(sf::Color::Red);
            }
            if (player.playerHealth <= 0) {
                //Setting this to false completely
                //stops the game, but wont exit.
                //Game over, you died. ;(
                ui.isWin = false;
                ui.isPlaying = false;
            }

            //Check for enemy collisions against the player
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                //The player is assumed to be alive or we
                //would not be playing.
                if (!enemyVector[i]->isDead) {
                    //Slight offset on the Y collision to make it
                    //look like the enemy is actually hitting the player hard
                    if (collisionbox.checkAABBcollision(player.playerSprite.getPosition().x - player.getWidth() / 2,
                                                        player.playerSprite.getPosition().y - player.getHeight() / 2 + 30,
                                                        player.getWidth(), player.getHeight(),
                                                        enemyVector[i]->positionX, enemyVector[i]->positionY,
                                                        enemy.getWidth(), enemy.getHeight())) {

                        //Kill the enemy, damage the player
                        audio.enemyDeath.play();
                        enemyVector[i]->isDead = true;
                        player.playerHealth -= 10;
                    }
                }
            }

            //Check for collision of enemies against shield
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                for (int j = 0; j < enemy.getMaxEnemies(); ++j) {
                    //Shield is up and enemy isnt dead
                    if (shield.shieldVector[i]->isShieldUp && !enemyVector[j]->isDead) {
                        if (collisionbox.checkAABBcollision(shield.shieldVector[i]->positionX, shield.shieldVector[i]->positionY,
                                                            30, 30, enemyVector[j]->positionX, enemyVector[j]->positionY,
                                                            enemy.getWidth(), enemy.getHeight())) {

                            //Take out a shield chunk and damage the enemy,
                            //Thus allowing the enemy to take out more shield
                            //chunks, ultimately destroying our shield in a cool way.
                            shield.shieldVector[i]->isShieldUp = false;
                            enemyVector[j]->applyDamage(enemy.enemyHealth / 2);
                            if (enemyVector[j]->isDead) {
                                audio.shieldImpact.play();
                            }
                        }
                    }
                }
            }

            //Check collision of enemies against laser
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                //Ensure we can damage our enemies with the laser
                if (laser.isLaserOn && !enemyVector[i]->isDead) {
                    if (collisionbox.checkAABBcollision(laser.laserSprite.getPosition().x,
                                                    laser.laserSprite.getPosition().y,
                                                    laser.getWidth(), laser.getHeight(),
                                                    enemyVector[i]->positionX, enemyVector[i]->positionY,
                                                    enemy.getWidth(), enemy.getHeight())) {

                        //Slowly damage the enemy, for
                        //a more realistic laser burn effect
                        enemyVector[i]->applyDamage(0.1);
                        if (enemyVector[i]->isDead) {
                            audio.enemyDeath.play();
                        }
                    }
                }
            }

            //Did any of our bullets collide with the enemies?
            //If so, damage the enemy and remove the bullet
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                for (int j = 0; j < enemy.getMaxEnemies(); ++j) {
                    //Ensure our bullet is actually capable of damaging our enemies
                    if (bullet.bulletStorage[i]->isActive && !enemyVector[j]->isDead) {
                        if (collisionbox.checkAABBcollision(bullet.bulletStorage[i]->positionX, bullet.bulletStorage[i]->positionY, 5, 5,
                                                            enemyVector[j]->positionX, enemyVector[j]->positionY,
                                                            enemy.getWidth(), enemy.getHeight())) {
                            //Collision detected.
                            bullet.bulletStorage[i]->isActive = false; //No longer rendered
                            enemyVector[j]->applyDamage(bullet.bulletStorage[i]->bulletDamage);
                            if (enemyVector[j]->isDead) {
                                audio.enemyDeath.play();
                            }
                        }
                    }
                }
            }

            //If a bullet misses and goes off screen, kill it too
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                if (bullet.bulletStorage[i]->positionY > SCREEN_HEIGHT || bullet.bulletStorage[i]->positionY < 0) {
                    bullet.bulletStorage[i]->isActive = false;
                }
            }

            //If the bullets are dead...
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                if (!bullet.bulletStorage[i]->isActive) {
                    //re-set their initial positions,
                    //so they can be used again
                    bullet.bulletStorage[i]->positionX = SCREEN_WIDTH / 2;
                    bullet.bulletStorage[i]->positionY = SCREEN_HEIGHT - player.getHeight();
                }
            }

            //If an enemy goes off screen, instant loss. Colony destroyed!
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                if (enemyVector[i]->positionY > SCREEN_HEIGHT) {
                    ui.isWin = false;
                    ui.isPlaying = false;
                }
            }
        }
        //END OF GAME LOGIC, START OF DRAWING STUFF

        //Clear window always
        window.clear(sf::Color::Black);
        //Always draw the background
        window.draw(background);
        //START OF UI EVENTS
        //Must be inside the draw loop,
        //because we are drawing/manipulating
        //our sprites
        if (ui.isMainMenu) {
            ui.isPlaying = false;
            //If we exit the help menu, actually exit from it.
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                ui.isHelpDisplayed = false;
            }
            //Draw all buttons
            window.draw(ui.helpButton);
            window.draw(ui.quitButton);
            window.draw(ui.startButton);
            if (ui.isHelpDisplayed) {
                window.draw(ui.helpPage);
            }
            //The start box collides with the mouse
            if (collisionbox.checkAABBcollision(ui.startButton.getPosition().x,
                                                ui.startButton.getPosition().y,
                                                ui.getWidth(), ui.getHeight(),
                                                mouse.getMouseX(), mouse.getMouseY(), 
                                                mouse.getWidth(), mouse.getHeight())) {
  
                //We press the start button...
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //Turn everything on...
                    for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                        shield.shieldVector[i]->isShieldUp = true;
                    }

                    //Reset enemy health
                    for (int i = 0; i < enemy.getMaxEnemies(); ++i){
                        enemyVector[i]->enemyHealth = enemy.getMaxEnemyHealth();
                    }

                    //Reset the player's health bar
                    player.healthBar.setFillColor(sf::Color::Green);

                    //Reset the player health
                    player.playerHealth = player.playerMaxHealth;

                    //Start playing
                    ui.isWin = false;
                    ui.isPlaying = true;
                    ui.isMainMenu = false;
                }
            }

            //If we press the help button...
            if (collisionbox.checkAABBcollision(ui.helpButton.getPosition().x,
                                    ui.helpButton.getPosition().y,
                                    ui.getWidth(), ui.getHeight(),
                                    mouse.getMouseX(), mouse.getMouseY(), 
                                    mouse.getWidth(), mouse.getHeight())) {
  
                //...turn the page on
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    ui.isHelpDisplayed = true;
                }
            }

            //If we press the quit button
            if (collisionbox.checkAABBcollision(ui.quitButton.getPosition().x,
                                    ui.quitButton.getPosition().y,
                                    ui.getWidth(), ui.getHeight(),
                                    mouse.getMouseX(), mouse.getMouseY(), 
                                    mouse.getWidth(), mouse.getHeight())) {
  
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //Quit
                    window.close();
                }
            }
        } // end ui.isMainMenu

        //Draw our game stuff only when
        //we are playing
        if (ui.isPlaying) {
            //Draw the enemies
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                if (!enemyVector[i]->isDead) { //The enemy is NOT dead...
                    //Apply gravity AKA make our enemies move down and towards player
                    enemyVector[i]->velocityY = enemyVector[i]->enemyVelocity + enemy.additionalEnemyVelocity;
                    enemyVector[i]->positionX += enemyVector[i]->velocityX * timeStep;
                    enemyVector[i]->positionY += enemyVector[i]->velocityY * timeStep;
                    enemyVector[i]->asteroidSprite.setPosition(enemyVector[i]->positionX, enemyVector[i]->positionY);
                    window.draw(enemyVector[i]->asteroidSprite);
                }
            }

            //Draw the bullets
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                if (bullet.bulletStorage[i]->isActive) { //Live bullet, so move it
                    bullet.bulletStorage[i]->positionX += bullet.bulletStorage[i]->velocityX * timeStep;
                    bullet.bulletStorage[i]->positionY += bullet.bulletStorage[i]->velocityY * timeStep;
                    bullet.bulletStorage[i]->bulletSprite.setPosition(bullet.bulletStorage[i]->positionX, bullet.bulletStorage[i]->positionY);
                    window.draw(bullet.bulletStorage[i]->bulletSprite);
                }
            }

            //Draw our laser
            if (laser.isLaserOn) {
                window.draw(laser.laserSprite);
            }

            //Draw our shield
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                if (shield.shieldVector[i]->isShieldUp) {
                    window.draw(shield.shieldVector[i]->shieldSprite);
                }
            }

            //Draw our player
            window.draw(player.playerSprite);

            //Draw our player's health bar
            window.draw(player.healthBar);
        } else { //ui.isPlaying is now FALSE
            //Kill everything because we are no longer playing
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                shield.shieldVector[i]->isShieldUp = false;
            }

            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                enemyVector[i]->isDead = true;
            }

            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                bullet.bulletStorage[i]->isActive = false;
            }

            //Ensure we are not in the main menu
            if (!ui.isMainMenu) {
                //If we won..
                if (ui.isWin) {
                    //Game victory text and prompt
                    window.draw(winText);
                    window.draw(spaceTostartText);
                } else { //We have lost
                    //Game over text and prompt
                    spaceTostartText.setString("spacebar to quit");
                    window.draw(gameOverText);
                    window.draw(spaceTostartText);
                    //Stop the music
                    audio.mainMenuTheme.stop();
                }

                //Space bar to re-start event
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    //Do the things that every win would require
                    if (ui.isWin) {
                        //Spawn more enemies
                        enemy.isWaveSpawned = false;

                        //Reset the enemy parameters
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemyVector[i]->enemyHealth = enemy.getMaxEnemyHealth();
                        }

                        //only reset enemies that need re-setting
                        for (int i = 0; i < enemy.getLocalEnemyCount(); ++i) {
                            enemyVector[i]->isDead = false;
                        }

                        //Enable the shields
                        for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                            shield.shieldVector[i]->isShieldUp = true;
                        }

                        //Start playing again
                        ui.isPlaying = true;

                        //Always re-set the win variable
                        ui.isWin = false;
                    } else { //We didnt win, must have lost
                        //Pressing spacebar should cause an exit
                        window.close();
                    }
                }
            }
        }
        //Display our window regardless
        //of if we are playing the game or not
        window.display();
    } //End game loop

	/*
    std::cout << "Cleaning up shields... Done\n";
    for (std::vector<Shield*>::iterator it = shieldVector.begin(); it != shieldVector.end(); it++){
        delete *it;
    }
    //*/

    std::cout << "Cleaning up enemies... Done\n";
    for (std::vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); it++){
        delete *it;
    }
} //End main
