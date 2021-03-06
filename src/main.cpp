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
    //const float timeStep = 1/60.0f;
    sf::Clock deltaClock;
    sf::Clock currClock;

    //Our window and event union
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_WIDTH = 800;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Attack of the Asteroids");
    sf::Event event;

    //Our square font
    sf::Font blockFont;
    if (!blockFont.loadFromFile("fonts/ehsmb.ttf")) {
    	std::cerr << "Warning: Missing font ehsmb.ttf\n";
    }

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
    sf::Text spaceToStartText;
    spaceToStartText.setFont(blockFont);
    spaceToStartText.setString("space bar to start");
    spaceToStartText.setCharacterSize(55);
    spaceToStartText.setFillColor(sf::Color::Yellow);
    spaceToStartText.setStyle(sf::Text::Regular);
    //Position this text just below our win/loss text
    spaceToStartText.setPosition(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 2);

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
    if (!backgroundTexture.loadFromFile("textures/bg.png")) {
    	std::cerr << "Warning: Missing texture file bg.png\n";
    }
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
        //Keep track of delta time
        sf::Time deltaTime = deltaClock.restart();
        sf::Time elapsedTime = currClock.getElapsedTime();
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

        //Process these events only if we are playing
        if (ui.isPlaying) {
            //Mouse down event. Shoot with left mouse
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				bullet.shoot(mouse, audio, deltaTime);
			}

            //Mouse right event. Fire our laser
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

        //Move the background
        /*
        sf::Time moveSpeed = sf::Time(sf::seconds(5));
        background.move(sin(((-moveSpeed.asSeconds() * deltaTime.asSeconds()) * currClock.getElapsedTime().asSeconds())), 0);
        if (background.getPosition().x <= -2200) {
            background.setPosition(0, 0);
        }
        std::cout << background.getPosition().x << std::endl;
        //*/

        //Running our actual game
        if (ui.isPlaying) {
            //Enemy wave spawning logic
            if (!enemy.isWaveSpawned) {
	            //Spawn 1 wave at a time
	            if (enemy.waveCounter == 1 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 1);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 2 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 2);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 3 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 3);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 4 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 4);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 5 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 5);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 6 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 6);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 7 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 7);
	                enemy.waveCounter += 1;
	                enemy.isWaveSpawned = true;
	            }
	            if (enemy.waveCounter == 8 && !enemy.isWaveSpawned) {
	                enemy.spawnEnemyWave(enemy.enemyVector, 8);
	                enemy.waveCounter = 8; //Do not add any more waves
	                enemy.isWaveSpawned = true;
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
                audio.laserFire.play();
                laser.tickTimer -= sf::seconds(0.25) * deltaTime.asSeconds();
                if (laser.tickTimer.asSeconds() <= 0) {
                    player.playerHealth -= laser.laserDamageToPlayer;
                    laser.tickTimer = laser.tickTimerInitial;
                }
            }

            //Check the status of our health bar
            //Allow the health bar to decrease in size over time
            player.healthBar.setRotation(180);
            player.healthBar.setScale(1.75, 0.1 + player.playerHealth / 100);
            //player.healthBar.setPosition(800 / 2 - 10, 600 + 25 - player.playerHealth);
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

            /* * * ROTATION CODE. WORKS BUT NEEDS IMPROVED UPON * * */
            //*
            //Rotate our enemies
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                if (enemy.enemyVector[i]->isAlive) {

                    //Set the rotation
                    enemy.enemyVector[i]->asteroidSprite.rotate(0.05);
                }
            }
            //*/

            //Check for enemy collisions against the player
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                //The player is assumed to be alive or we
                //would not be playing.
                if (enemy.enemyVector[i]->isAlive) {
                    //Slight offset on the Y collision to make it
                    //look like the enemy is actually hitting the player hard
                    if (collisionbox.checkAABBcollision(player.playerSprite.getPosition().x - player.getWidth() / 2,
                                                        player.playerSprite.getPosition().y - player.getHeight() / 2 + 30,
                                                        player.getWidth(), player.getHeight(),
                                                        enemy.enemyVector[i]->positionX - 32, enemy.enemyVector[i]->positionY - 32, 64, 64)) {

                        //Kill the enemy, damage the player
                        audio.enemyDeath.play();
                        enemy.enemyVector[i]->isAlive = false;
                        player.playerHealth -= 10;
                    }
                }
            }

            //Check for collision of enemies against shield
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                for (int j = 0; j < enemy.getMaxEnemies(); ++j) {
                    //Shield is up and enemy isnt dead
                    if (shield.shieldVector[i]->isShieldUp && enemy.enemyVector[j]->isAlive) {
                        if (collisionbox.checkAABBcollision(shield.shieldVector[i]->positionX, shield.shieldVector[i]->positionY,
                                                            30, 30, enemy.enemyVector[j]->positionX - 32, enemy.enemyVector[j]->positionY - 32,
                                                            60, 60)) {

                            //Take out a shield chunk and damage the enemy,
                            //Thus allowing the enemy to take out more shield
                            //chunks, ultimately destroying our shield in a cool way.
                            shield.shieldVector[i]->isShieldUp = false;
                            enemy.enemyVector[j]->enemyHealth -= 20;
                            if (enemy.enemyVector[j]->enemyHealth <= 0) {
                            	enemy.enemyVector[j]->isAlive = false;
                            }
                            if (!enemy.enemyVector[j]->isAlive) {
                                audio.shieldImpact.play();
                            }
                        }
                    }
                }
            }

            //Check collision of enemies against laser
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                //Ensure we can damage our enemies with the laser
                if (laser.isLaserOn && enemy.enemyVector[i]->isAlive) {
                    if (collisionbox.checkAABBcollision(laser.laserSprite.getPosition().x,
                                                    laser.laserSprite.getPosition().y,
                                                    laser.getWidth(), laser.getHeight(),
                                                    enemy.enemyVector[i]->positionX - 32, enemy.enemyVector[i]->positionY - 32,
                                                    60, 60)) {

                        //Slowly damage the enemy, for
                        //a more realistic laser burn effect
                        enemy.enemyVector[i]->enemyHealth -= laser.laserDamage;
                        if (enemy.enemyVector[i]->enemyHealth <= 0) {
                        	enemy.enemyVector[i]->isAlive = false;
                        }
                        if (!enemy.enemyVector[i]->isAlive) {
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
                    if (bullet.bulletStorage[i]->isActive && enemy.enemyVector[j]->isAlive) {
                        if (collisionbox.checkAABBcollision(bullet.bulletStorage[i]->positionX, bullet.bulletStorage[i]->positionY, 5, 5,
                                                            enemy.enemyVector[j]->positionX - 32, enemy.enemyVector[j]->positionY - 32,
                                                            60, 60)) {
                            //Collision detected.
                            bullet.bulletStorage[i]->isActive = false; //No longer rendered
                            enemy.enemyVector[j]->enemyHealth -= bullet.bulletStorage[i]->bulletDamage;
                            if (enemy.enemyVector[j]->enemyHealth <= 0) {
                            	enemy.enemyVector[j]->isAlive = false;
                            }
                            if (!enemy.enemyVector[j]->isAlive) {
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
                    ui.isLoss = true;
                }
            }

            //If a shield died, move it off screen for special effect
            for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                if (!shield.shieldVector[i]->isShieldUp) {
                    shield.shieldVector[i]->positionY += 100.0 * deltaTime.asSeconds();
                    shield.shieldVector[i]->shieldSprite.setPosition(shield.shieldVector[i]->shieldSprite.getPosition().x, shield.shieldVector[i]->positionY);
                }
            }

            //Change the opacity of a dead asteroid sprite over time to fade out
            for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                if (!enemy.enemyVector[i]->isAlive) {
                    enemy.enemyVector[i]->opacity -= (sf::seconds(500) * deltaTime.asSeconds());
                    //Use the opacity variable to also fade out our other colors.
                    sf::Time colorMod = enemy.enemyVector[i]->opacity;
                    enemy.enemyVector[i]->asteroidSprite.setColor(sf::Color(colorMod.asSeconds(), colorMod.asSeconds(),
                                                                            colorMod.asSeconds(), colorMod.asSeconds()));
                }
                if (enemy.enemyVector[i]->asteroidSprite.getColor().a <= 0) {
                    enemy.enemyVector[i]->isRendered = false;
                }
                if (enemy.enemyVector[i]->opacity.asSeconds() <= 0) {
                    enemy.enemyVector[i]->opacity = sf::seconds(255);
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
                if (enemy.enemyVector[i]->isAlive) { //The enemy is NOT dead...
                    //Apply gravity AKA make our enemies move down and towards player
                    enemy.enemyVector[i]->velocityY = enemy.enemyVector[i]->enemyVelocity;
                    enemy.enemyVector[i]->positionX = enemy.enemyVector[i]->positionX + (enemy.enemyVector[i]->velocityX * deltaTime.asSeconds());
                    enemy.enemyVector[i]->positionY = enemy.enemyVector[i]->positionY + (enemy.enemyVector[i]->velocityY * deltaTime.asSeconds());
                    enemy.enemyVector[i]->asteroidSprite.setPosition(enemy.enemyVector[i]->positionX, enemy.enemyVector[i]->positionY);
                    window.draw(enemy.enemyVector[i]->asteroidSprite);
                } else {
                    if (enemy.enemyVector[i]->isRendered) {
                        window.draw(enemy.enemyVector[i]->asteroidSprite);
                    }
                }
            }

            //Draw the bullets
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                if (bullet.bulletStorage[i]->isActive) { //Live bullet, so move it
                    bullet.bulletStorage[i]->positionX = bullet.bulletStorage[i]->positionX + (bullet.bulletStorage[i]->velocityX * deltaTime.asSeconds());
                    bullet.bulletStorage[i]->positionY = bullet.bulletStorage[i]->positionY + (bullet.bulletStorage[i]->velocityY * deltaTime.asSeconds());
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
                } else {
                    if (shield.shieldVector[i]->shieldSprite.getPosition().y < SCREEN_HEIGHT) {
                      window.draw(shield.shieldVector[i]->shieldSprite);
                    }
                }
            }

            //Draw our player
            window.draw(player.playerSprite);

            //Draw our player's health bar
            window.draw(player.healthBarBackground);
            window.draw(player.healthBar);

        } else { //ui.isPlaying is now FALSE
            for (int i = 0; i < bullet.getMaxBullets(); ++i) {
                bullet.bulletStorage[i]->isActive = false;
            }

            //Ensure we are not in the main menu
            if (!ui.isMainMenu) {
                //If we won..
                if (ui.isWin) {
                    //Game victory text and prompt
                    window.draw(winText);
                    window.draw(spaceToStartText);
                } else { //We have lost
                    //Game over text and prompt
                    spaceToStartText.setString("spacebar to quit");
                    window.draw(gameOverText);
                    window.draw(spaceToStartText);
                    //Stop the music
                    audio.mainMenuTheme.stop();
                }


                //Do the things that every win would require
                if (ui.isWin) {
                    //Space bar to re-start event
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        //Spawn more enemies
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.isWaveSpawned = false;
                        }

                        //Reset the enemy parameters
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.enemyVector[i]->enemyHealth = 40;
                        }

                        //only reset enemies that need re-setting
                        for (int i = 0; i < enemy.getLocalEnemyCount(); ++i) {
                            enemy.enemyVector[i]->isAlive = true;
                       }

                        //Cleanup dead shield blocks by moving everything off screen
                        for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                            if (!shield.shieldVector[i]->isShieldUp) {
                                shield.shieldVector[i]->shieldSprite.setPosition(-9000, -9000);
                            }
                        }

                        //Reset multiple enemy variables
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.enemyVector[i]->isRendered = true;
                            enemy.enemyVector[i]->asteroidSprite.setColor(sf::Color(255, 255, 255, 255));
                            enemy.enemyVector[i]->opacity = sf::seconds(255);
                        }

                        //Start playing again
                        ui.isPlaying = true;

                        //Always re-set the win variable
                        ui.isWin = false;
                    }
                }
               if (ui.isLoss) {
                    //We didn't win, so we must have lost.
                    //Offer to quit, otherwise spacebar to completely
                    //reset and play again.
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                        window.close();
                    }

                    //Start a new game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        //Spawn more enemies
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                        	enemy.isWaveSpawned = false;
                        }

                        //Reset the enemy parameters
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.enemyVector[i]->enemyHealth = 40;
                        }

                        //only reset enemies that need re-setting
                        for (int i = 0; i < enemy.getLocalEnemyCount(); ++i) {
                            enemy.enemyVector[i]->isAlive = true;
                       }

                        //Cleanup dead shield blocks by moving everything off screen
                        for (int i = 0; i < shield.getMaxShieldBlocks(); ++i) {
                            if (!shield.shieldVector[i]->isShieldUp) {
                                shield.shieldVector[i]->shieldSprite.setPosition(-9000, -9000);
                            }
                        }

                        //Reset multiple enemy variables
                        for (int i = 0; i < enemy.getMaxEnemies(); ++i) {
                            enemy.enemyVector[i]->isRendered = true;
                            enemy.enemyVector[i]->asteroidSprite.setColor(sf::Color(255, 255, 255, 255));
                        }

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

                        //Reset the wave counter
                        enemy.waveCounter = 1;

                        //Start playing
                        ui.isWin = false;
                        ui.isPlaying = false;
                        ui.isMainMenu = true;
                        ui.isLoss = false;
                    }
                }
            }
        }
        //Display our window regardless
        //of if we are playing the game or not
        window.display();
    } //End game loop
} //End main
