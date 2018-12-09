#ifndef PLAYERCONTROLLEDSNAKE_H
#define PLAYERCONTROLLEDSNAKE_H

#include "Snake.h"


class PlayerControlledSnake : public Snake
{
    public:
        PlayerControlledSnake();

        void ChangeDirection() override;
        void Draw(sf::RenderWindow &WindowIn) override;

        bool UpPressed();
        bool DownPressed();
        bool LeftPressed();
        bool RightPressed();
};

#endif // PLAYERCONTROLLEDSNAKE_H
