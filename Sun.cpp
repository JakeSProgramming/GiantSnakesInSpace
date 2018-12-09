#include "Sun.h"

Sun::Sun()
{
    SFMLSun.setPosition({640,480});
    SFMLSun.setOrigin({SFMLSun.getRadius(), SFMLSun.getRadius()});
    SFMLSun.setFillColor(sf::Color::Yellow);
    SFMLSun.setOutlineColor(sf::Color(255, 140, 0));
    SFMLSun.setOutlineThickness(5.f);
}

void Sun::Draw(sf::RenderWindow &WindowIn)
{
    WindowIn.draw(SFMLSun);
}
