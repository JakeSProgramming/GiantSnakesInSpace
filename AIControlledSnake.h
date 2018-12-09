#ifndef AICONTROLLEDSNAKE_H
#define AICONTROLLEDSNAKE_H

#include "Snake.h"


class AIControlledSnake : public Snake
{
    public:
        AIControlledSnake(int Colour);
        virtual ~AIControlledSnake();
        void Draw(sf::RenderWindow &WindowIn) override;

        void ChangeDirection() override;

    private:
        EDirection StartDir {EDirection::eLeft};

};

#endif // AICONTROLLEDSNAKE_H
