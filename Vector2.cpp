#include "Vector2.h"

Vector2::Vector2()
{

}

Vector2::Vector2(float xin, float yin): x(xin) , y(yin)
{

}

Vector2::Vector2(const Vector2& other)
{
    x = other.x;
    y = other.y;

}

Vector2::~Vector2()
{

}
