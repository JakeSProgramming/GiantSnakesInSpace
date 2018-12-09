#include "PickUp.h"

PickUp::PickUp()
{
    PointValue = rand() % 5 + 1;
}

void PickUp::SetNewPosition(int ScreenWidthIn, int ScreenHeightIn)
{
    int SpawnPosX=(rand()%(((ScreenWidthIn - 10) + 5)/40))*40;
    int SpawnPosY=(rand()%(((ScreenHeightIn - 10) + 5)/40))*40;

    while (SpawnPosX < 10 || SpawnPosX > ScreenWidthIn - 10 || (SpawnPosX < 690 && SpawnPosX > 590))
    {
        SpawnPosX=(rand()%(((ScreenWidthIn - 10) + 5)/40))*40;
    }

    while (SpawnPosY < 10 || SpawnPosY > ScreenHeightIn - 10 || (SpawnPosY < 530 && SpawnPosY > 430))
    {
        SpawnPosY=(rand()%(((ScreenHeightIn - 10) + 5)/40))*40;
    }

    PickUpPosition.x = SpawnPosX;
    PickUpPosition.y = SpawnPosY;

    Alive = true;
    PointValue = rand() % 5 + 1;
}

void PickUp::Draw(sf::RenderWindow &WindowIn)
{
    if (Alive)
    {
        sf::CircleShape PickupDraw(10.f);

        switch (PointValue)
        {
        case 1:
            PickupDraw.setFillColor(sf::Color::Yellow);
            break;
        case 2:
            PickupDraw.setFillColor(sf::Color::Blue);
            break;
        case 3:
            PickupDraw.setFillColor(sf::Color::Green);
            break;
        case 4:
            PickupDraw.setFillColor(sf::Color::Magenta);
            break;
        case 5:
            PickupDraw.setFillColor(sf::Color::Red);
            break;
        }

        PickupDraw.setPosition(PickUpPosition);
        PickupDraw.setOrigin(sf::Vector2f(10, 10));
        WindowIn.draw(PickupDraw);
    }
}

bool PickUp::IsAlive()
{
    return Alive;
}

void PickUp::SetAlive(bool AliveIn)
{
    Alive = AliveIn;
}

sf::Vector2f PickUp::GetPosition()
{
    return PickUpPosition;
}

int PickUp::GetPointValue()
{
    return PointValue;
}
