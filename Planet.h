#ifndef PLANET_H
#define PLANET_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Snake.h"

class Planet
{
    public:
        Planet(float DistanceXIn, float DistanceYIn);

        void Move();
        void Draw(sf::RenderWindow &WindowIn);

        void CheckCollideSnake(Snake &SnakeIn);
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

    private:
        sf::CircleShape SFMLPlanet{30.f};
        sf::Vector2f PlanetPosition{640 - DistanceX, 480 - DistanceY};

        float DistanceX {0};
        float DistanceY {0};
};

#endif // PLANET_H
