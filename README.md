# A.O.T.A - Attack of the Asteroids
Welcome to AOTA! This is a 2D game that I'm currently working on on. I hope you will enjoy playing!

## System Requirements
This game requires SFML >= 2.4 but may work work with older versions of sfml with varying success.
This game requires a Linux based OS. Currently Arch Linux is the only tested OS but Ubuntu or Mint or Debian 
or whatever should work too. Winows OS and Mac are unsupported but may work to some extent.
Make is required to build the project.

## Installation
For Arch Linux, use the provided PKGBUILD. To run a copy locally, edit the cpp files and replace 
/usr/share/attackoftheasteroids 
with ../ so for example: 
blockFont.loadFromFile("/usr/share/attackoftheasteroids/fonts/ehsmb.ttf");
becomes
blockFont.loadFromFile("../fonts/ehsmb.ttf");
repeat for each .loadFromFile() that needs changing. 
Then, cd src/; make; ./aota
### I am planning on making some sort of configuration script/code soon to make this easier or even automate the process.

## Ingame Controls
Left mouse: Shoot main cannon.
Right mouse: Fire side laser.
Mouse Movement: Aim main cannon.

For additional help there in an ingame help graphic by clicking "HELP" in the main menu.

## Author's notes
This is a revival of a really old project (MessyFoods) that was abandoned in a bad state. If you really want to view this
project, go here:https://github.com/JohnBobSmith/MessyFoods. For AOTA, I hope to restore basic gameplay and keep my asteroids 
theme, while also adding some new mechanics and other gameplay features.

## Credits
Thanks to anyone who has helped me with MessyFoods or this project in any way, shape, or form. You (hopefully) know you who
are. The help is always appreciated! :)

Included is the electronic highway font as 100% free so I hope I can use it here: 
https://www.dafont.com/electronic-highway-sign.font

All of the code, art, and audio or other assets are mine unless otherwise stated. Feel free to use them as you see fit subject 
to the MIT license. 

Thanks for your interest in my project! :D
