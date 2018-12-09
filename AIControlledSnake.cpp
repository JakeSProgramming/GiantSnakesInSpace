#include "AIControlledSnake.h"

//TODO Setup AI

AIControlledSnake::AIControlledSnake(int Colour)
{
    srand(time(0));

    switch (Colour)
    {
    case 0:
        HeadPos = {1240,40};
        break;
    case 1:
        HeadPos = {40,920};
        break;
    case 2:
        HeadPos = {1240,920};
        break;
    };

    StartPos = {1240, 920};
}

AIControlledSnake::~AIControlledSnake()
{
    //dtor
}

void AIControlledSnake::Draw(sf::RenderWindow &WindowIn)
{
    if (IsAlive)
    {
        for (auto i : SnakePositions)
        {
            sf::CircleShape SnakeDraw{20.f};
            SnakeDraw.setPosition(i);
            SnakeDraw.setOrigin(sf::Vector2f(SnakeDraw.getRadius(), SnakeDraw.getRadius()));
            WindowIn.draw(SnakeDraw);
        }
    }
    std::cout << StartPos.x << " " << StartPos.y << std::endl;
}

void AIControlledSnake::ChangeDirection()
{
    int Change = rand() % 4;

    switch(Change)
    {
    case 0:
        Direction = EDirection::eLeft;
        break;
    case 1:
        Direction = EDirection::eRight;
        break;
    case 2:
        Direction = EDirection::eUp;
        break;
    case 3:
        Direction = EDirection::eDown;
        break;
    }
}
