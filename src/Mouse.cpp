#include "include/Mouse.h"

float Mouse::calculateMouseAngle(float mouseX, float mouseY, float positionX, float positionY)
{
    //Calcualte the mouse angle with atan2.
    float angle = std::atan2(mouseY - positionY, mouseX - positionX);
    angle = angle * 180 / M_PI;
    if (angle < 0) {
        angle = 360 -(-angle);
    }
    return angle;
}

void Mouse::update(sf::Event &event)
{
    //Calculate the mouse position every frame
    if (event.type == sf::Event::MouseMoved) {
        mouseX = event.mouseMove.x;
        mouseY = event.mouseMove.y;
    }
}

float Mouse::getMouseAngle()
{
    //Set the angle relative to the player
    mouseAngle = calculateMouseAngle(mouseX, mouseY, 800 / 2, 600 - 128);

    return mouseAngle;
}
