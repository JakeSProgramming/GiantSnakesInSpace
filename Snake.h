#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <list>
#include <sstream>

#include "Vector2.h"
#include "PickUp.h"

class Snake
{
    public:
        Snake();
        ~Snake();

        void Move();
        void Reset();

        //Virtual Functions
        virtual void ChangeDirection() = 0;
        virtual void Draw(sf::RenderWindow &WindowIn) = 0;

        //Getters
        std::list <sf::Vector2f>& GetSnakePositions();
        bool GetAlive();
        int GetPoints();

        //Setters
        void SetAlive(bool AliveIn);
        void SetPoints(int PointsIn);

        //Checks
        void CheckCollideSelf();
        void CheckCollideWalls();
        void CheckCollideSnake(Snake &SnakeIn);
        void CheckCollidePickUp(std::vector <PickUp> &PickUpIn);
        void CheckCollideSun();

     protected:
        sf::Vector2f HeadPos {40,40};
        sf::Vector2f StartPos {40,40};
        std::list <sf::Vector2f> SnakePositions;
        int Points = 0;
        int GrowAmount = 0;
        sf::Font PointsFont;

        enum class EDirection
        {
            eUp,
            eLeft,
            eDown,
            eRight
        };

        bool IsAlive = true;

        EDirection Direction {EDirection::eRight};
        EDirection StartDir {EDirection::eRight};
};

#endif // SNAKE_H
