#ifndef SUN_H
#define SUN_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Sun
{
    public:
        Sun();

        void Draw(sf::RenderWindow &WindowIn);

    private:
        float Radius {50.f};
        sf::CircleShape SFMLSun{Radius};
};

#endif // SUN_H
