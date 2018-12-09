#include "PlayerControlledSnake.h"

PlayerControlledSnake::PlayerControlledSnake()
{
    //ctor
}

void PlayerControlledSnake::Draw(sf::RenderWindow &WindowIn)
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

    std::stringstream ss;
    ss << Points;
    std::string PointsS = ss.str();

    sf::Text PointsText(PointsS, PointsFont, 20);
    PointsText.setColor(sf::Color::Black);
    PointsText.setPosition(sf::Vector2f(150,25));
    WindowIn.draw(PointsText);

    ss.str("");
    std::string PlayerText = "Player 1 = ";
    ss << PlayerText;
    std::string PlayerTextS = ss.str();

    sf::Text PlayerTextT(PlayerTextS, PointsFont, 20);
    PlayerTextT.setColor(sf::Color::Black);
    PlayerTextT.setPosition(sf::Vector2f(25,25));
    WindowIn.draw(PlayerTextT);
}

void PlayerControlledSnake::ChangeDirection()
{
    if(LeftPressed() && Direction != EDirection::eRight)
    {
        Direction = EDirection::eLeft;
    }
    else if(RightPressed() && Direction != EDirection::eLeft)
    {
        Direction = EDirection::eRight;
    }
    else if(UpPressed() && Direction != EDirection::eDown)
    {
        Direction = EDirection::eUp;
    }
    else if(DownPressed() && Direction != EDirection::eUp)
    {
        Direction = EDirection::eDown;
    }
    else
    {
        Direction = Direction;
    }
}

bool PlayerControlledSnake::UpPressed()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PlayerControlledSnake::DownPressed()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PlayerControlledSnake::LeftPressed()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PlayerControlledSnake::RightPressed()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        return true;
    }
    else
    {
        return false;
    }
}
