#ifndef PICKUP_H
#define PICKUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class PickUp
{
    public:
        PickUp();

        void SetNewPosition(int ScreenWidthIn, int ScreenHeightIn);
        void Draw(sf::RenderWindow &WindowIn);
        sf::Vector2f GetPosition();
        bool IsAlive();
        void SetAlive(bool AliveIn);
        int GetPointValue();

    private:
        sf::Vector2f PickUpPosition;
        int PointValue;
        bool Alive = true;

};

#endif // PICKUP_H
