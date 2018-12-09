#include "Snake.h"

Snake::Snake()
{
    Reset();
    if (!PointsFont.loadFromFile("ARCADE.TTF"));
}

Snake::~Snake()
{
    SnakePositions.clear();
}

void Snake::Move()
{
    if (IsAlive)
    {
        ChangeDirection();
        CheckCollideSelf();
        CheckCollideWalls();
        CheckCollideSun();

        if (Direction == EDirection::eUp)
        {
            sf::Vector2f NewSnakePos(HeadPos.x, HeadPos.y -= 40);
            SnakePositions.push_front(NewSnakePos);
        }
        else if (Direction == EDirection::eRight)
        {
            sf::Vector2f NewSnakePos(HeadPos.x += 40, HeadPos.y);
            SnakePositions.push_front(NewSnakePos);
        }
        else if (Direction == EDirection::eDown)
        {
            sf::Vector2f NewSnakePos(HeadPos.x, HeadPos.y += 40);
            SnakePositions.push_front(NewSnakePos);
        }
        else if (Direction == EDirection::eLeft)
        {
            sf::Vector2f NewSnakePos(HeadPos.x -= 40, HeadPos.y);
            SnakePositions.push_front(NewSnakePos);
        }

        if (GrowAmount > 0)
        {
            GrowAmount--;
        }
        else
        {
            SnakePositions.pop_back();
        }
    }

}

void Snake::CheckCollideWalls()
{
        if (HeadPos.x < 10)
        {
            IsAlive = false;
        }

        if (HeadPos.x > 1260)
        {
            IsAlive = false;
        }

        if (HeadPos.y < 10)
        {
            IsAlive = false;
        }

        if (HeadPos.y > 940)
        {
            IsAlive = false;
        }
}

void Snake::CheckCollideSnake(Snake &SnakeIn)
{
    if (IsAlive)
    {
        auto it = SnakeIn.GetSnakePositions().begin();

        while(it != SnakeIn.GetSnakePositions().end())
        {
            if (HeadPos.x == (*it).x && HeadPos.y == (*it).y)
            {
                IsAlive = false;
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
}

void Snake::CheckCollideSelf()
{
    if (IsAlive)
    {
        auto it = SnakePositions.begin();
        it++;

        while(it!=SnakePositions.end())
        {
            if (HeadPos.x == (*it).x && HeadPos.y == (*it).y)
            {
                ///What happens when snake hits itself
                IsAlive = false;
            }

            it++;
        }
    }
}

void Snake::CheckCollidePickUp(std::vector <PickUp> &PickUpIn)
{
    if (IsAlive)
    {
        for (int i = 0; i < PickUpIn.size(); i++)
        {
            if (HeadPos.x == PickUpIn[i].GetPosition().x && HeadPos.y == PickUpIn[i].GetPosition().y)
            {
                PickUpIn[i].SetAlive(false);
                GrowAmount += PickUpIn[i].GetPointValue();
                Points += PickUpIn[i].GetPointValue();
            }
        }
    }
}

void Snake::CheckCollideSun()
{
    if (HeadPos.x < 690 && HeadPos.x > 590 && HeadPos.y < 530 && HeadPos.y > 430)
    {
        IsAlive = false;
    }
}

std::list <sf::Vector2f>& Snake::GetSnakePositions()
{
    return SnakePositions;
}

bool Snake::GetAlive()
{
    return IsAlive;
}

void Snake::SetAlive(bool AliveIn)
{
    IsAlive = AliveIn;

    if (AliveIn == false)
    {
        SnakePositions.clear();
    }
}

void Snake::Reset()
{
    SnakePositions.erase(SnakePositions.begin(), SnakePositions.end());
    Direction = StartDir;
    HeadPos = StartPos;
    SnakePositions.push_back(StartPos);
    Points = 0;
    GrowAmount = 0;
    IsAlive = true;
}

void Snake::SetPoints(int PointsIn)
{
    Points = PointsIn;
}

int Snake::GetPoints()
{
    return Points;
}
