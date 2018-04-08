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

	//Our enemies
	Enemy enemy;
	
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
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
		        if (!enemy.enemyVector[i]->isWaveSpawned) {
		            //Spawn 1 wave at a time
		            static int counter = 1;
		            //Because our counter variable is not
		            //A constant expression, we must use
		            //if statements instead of case, or
		            //we get a compiler error.
		            if (counter == 1 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 1);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 2 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 2);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 3 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 3);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 4 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 4);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 5 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 5);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 6 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 6);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 7 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 7);
		                counter += 1;
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		            if (counter == 8 && !enemy.enemyVector[i]->isWaveSpawned) {
		                enemy.spawnEnemyWave(enemy.enemyVector, 8);
		                counter = 8; //Do not add any more waves
		                enemy.enemyVector[i]->isWaveSpawned = true;
		            }
		        }
            }
            //Win checking
            //This is done right away, so that if this
            //returns false, checking for a loss still occurs
            if (enemy.checkForWin(enemy.enemyVector, enemy.getLocalEnemyCount())) {
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
                if (!enemy.enemyVector[i]->isDead) {
                    //Slight offset on the Y collision to make it
                    //look like the enemy is actually hitting the player hard
                    if (collisionbox.checkAABBcollision(player.playerSprite.getPosition().x - player.getWidth() / 2,
                                                        player.playerSprite.getPosition().y - player.getHeight() / 2 + 30,
                                                        player.getWidth(), player.getHeight(),
                                                        enemy.enemyVector[i]->positionX, enemy.enemyVector[i]->positionY, 64, 64)) {

                        //Kill the enemy, damage the player
                        audio.enemyDeath.play();
                        enemy.enemyVector[i]->isDead = true;
                        player.playerHealth -= 10;
                    }
                }
            }

            //Check for collision of enemies against shield
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                for (int j = 0; j < enemy.getMaxEnemies(); ++j) {
                    //Shield is up and enemy isnt dead
                    if (shield.shieldVector[i]->isShieldUp && !enemy.enemyVector[j]->isDead) {
                        if (collisionbox.checkAABBcollision(shield.shieldVector[i]->positionX, shield.shieldVector[i]->positionY,
                                                            30, 30, enemy.enemyVector[j]->positionX, enemy.enemyVector[j]->positionY,
                                                            60, 60)) {

                            //Take out a shield chunk and damage the enemy,
                            //Thus allowing the enemy to take out more shield
                            //chunks, ultimately destroying our shield in a cool way.
                            shield.shieldVector[i]->isShieldUp = false;
                            enemy.enemyVector[j]->enemyHealth -= 20;
                            if (enemy.enemyVector[j]->enemyHealth <= 0) {
                            	enemy.enemyVector[j]->isDead = true;
                            }
                            if (enemy.enemyVector[j]->isDead) {
                                audio.shieldImpact.play();
                            }
                        }
                    }
                }
            }

            //Check collision of enemies against laser
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                //Ensure we can damage our enemies with the laser
                if (laser.isLaserOn && !enemy.enemyVector[i]->isDead) {
                    if (collisionbox.checkAABBcollision(laser.laserSprite.getPosition().x,
                                                    laser.laserSprite.getPosition().y,
                                                    laser.getWidth(), laser.getHeight(),
                                                    enemy.enemyVector[i]->positionX, enemy.enemyVector[i]->positionY,
                                                    60, 60)) {

                        //Slowly damage the enemy, for
                        //a more realistic laser burn effect
                        enemy.enemyVector[i]->enemyHealth -= 0.1;
                        if (enemy.enemyVector[i]->enemyHealth <= 0) {
                        	enemy.enemyVector[i]->isDead = true;
                        }
                        if (enemy.enemyVector[i]->isDead) {
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
                    if (bullet.bulletStorage[i]->isActive && !enemy.enemyVector[j]->isDead) {
                        if (collisionbox.checkAABBcollision(bullet.bulletStorage[i]->positionX, bullet.bulletStorage[i]->positionY, 5, 5,
                                                            enemy.enemyVector[j]->positionX, enemy.enemyVector[j]->positionY,
                                                            60, 60)) {
                            //Collision detected.
                            bullet.bulletStorage[i]->isActive = false; //No longer rendered
                            enemy.enemyVector[j]->enemyHealth -= bullet.bulletStorage[i]->bulletDamage;
                            if (enemy.enemyVector[j]->enemyHealth <= 0) {
                            	enemy.enemyVector[j]->isDead = true;
                            }
                            if (enemy.enemyVector[j]->isDead) {
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
                if (enemy.enemyVector[i]->positionY > SCREEN_HEIGHT) {
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
                        enemy.enemyVector[i]->enemyHealth = 40;
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
                if (!enemy.enemyVector[i]->isDead) { //The enemy is NOT dead...
                    //Apply gravity AKA make our enemies move down and towards player
                    enemy.enemyVector[i]->velocityY = enemy.enemyVector[i]->enemyVelocity;
                    enemy.enemyVector[i]->positionX += enemy.enemyVector[i]->velocityX * timeStep;
                    enemy.enemyVector[i]->positionY += enemy.enemyVector[i]->velocityY * timeStep;
                    enemy.enemyVector[i]->asteroidSprite.setPosition(enemy.enemyVector[i]->positionX, enemy.enemyVector[i]->positionY);
                    window.draw(enemy.enemyVector[i]->asteroidSprite);
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
                enemy.enemyVector[i]->isDead = true;
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
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                        	enemy.enemyVector[i]->isWaveSpawned = false;
                        }

                        //Reset the enemy parameters
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.enemyVector[i]->enemyHealth = 40;
                        }

                        //only reset enemies that need re-setting
                        for (int i = 0; i < enemy.getLocalEnemyCount(); ++i) {
                            enemy.enemyVector[i]->isDead = false;
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
} //End main
