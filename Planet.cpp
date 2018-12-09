#include "Planet.h"

Planet::Planet(float DistanceXIn, float DistanceYIn)
{
    DistanceX = DistanceXIn;
    DistanceY = DistanceYIn;
    SFMLPlanet.setOrigin(SFMLPlanet.getRadius(), SFMLPlanet.getRadius());
    SFMLPlanet.setFillColor(sf::Color::Blue);
    PlanetPosition = sf::Vector2f(640 - DistanceX, 480 - DistanceY);
    SFMLPlanet.setPosition(PlanetPosition);
}


void Planet::Move()
{
    //320 480
    if (PlanetPosition.x == (640 - DistanceX) && PlanetPosition.y > (480 - DistanceY))
    {
        MoveUp();
    }
    else if (PlanetPosition.x == (640 + DistanceX) && PlanetPosition.y < (480 + DistanceY))
    {
        MoveDown();
    }
    else if (PlanetPosition.y == (480 - DistanceY) && PlanetPosition.x < (640 + DistanceX))
    {
        MoveRight();
    }
    else if (PlanetPosition.y == (480 + DistanceY) && PlanetPosition.x > (640 - DistanceX))
    {
        MoveLeft();
    }
}

void Planet::Draw(sf::RenderWindow &WindowIn)
{
    WindowIn.draw(SFMLPlanet);
}

void Planet::CheckCollideSnake(Snake &SnakeIn)
{
    //TODO Set Snake to dead when head is hit
    auto it = SnakeIn.GetSnakePositions().begin();

    while(it != SnakeIn.GetSnakePositions().end())
    {
        if (PlanetPosition.x + 30 >= (*it).x - 20 && PlanetPosition.x - 30 <= (*it).x + 20 && PlanetPosition.y + 30 >= (*it).y - 20 && PlanetPosition.y - 30 <= (*it).y + 20)
        {
            ///What happens when snake hits planet
           if (it == SnakeIn.GetSnakePositions().begin())
            {
                SnakeIn.GetSnakePositions().erase(it, SnakeIn.GetSnakePositions().end());
                SnakeIn.SetAlive(false);
                break;
            }
            SnakeIn.GetSnakePositions().erase(it, SnakeIn.GetSnakePositions().end());
            SnakeIn.SetPoints((SnakeIn.GetSnakePositions().size()) - 1);
            break;
        }
        if (it != SnakeIn.GetSnakePositions().end())
        {
            it++;
        }
        else
        {
            break;
        }
    }
}

void Planet::MoveUp()
{
    SFMLPlanet.move(0, -40);
    PlanetPosition.y -= 40;
}

void Planet::MoveDown()
{
    SFMLPlanet.move(0, 40);
    PlanetPosition.y += 40;
}

void Planet::MoveLeft()
{
    SFMLPlanet.move(-40, 0);
    PlanetPosition.x -= 40;
}

void Planet::MoveRight()
{
    SFMLPlanet.move(40, 0);
    PlanetPosition.x += 40;
}
