#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>


class Vector2
{
    public:
        //Functions

        Vector2();
        Vector2(float xin, float yin);
        Vector2(const Vector2& other);
        ~Vector2();

        Vector2& operator+=(const Vector2& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;

        }

        Vector2& operator-=(const Vector2& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;

        }

        Vector2& operator=(Vector2 rhs)
        {
            std::swap(x, rhs.x);
            std::swap(y, rhs.y);
            return *this;
        }



        //Variables

        float x {0};
        float y {0};


    protected:

    private:

};

inline Vector2 operator + (Vector2 lhs, const Vector2& rhs)
{
    lhs += rhs;
    return lhs;

}

inline Vector2 operator - (Vector2 lhs, const Vector2& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;

}

inline Vector2 operator * (Vector2 lhs, const float& rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;

}

inline Vector2 operator / (Vector2 lhs, const float& rhs)
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;

}

inline bool operator== (const Vector2& lhs, const Vector2& rhs)
{
    if ((lhs.x == rhs.x) && (lhs.y == rhs.y))
    {
        return true;
    }

    return false;
}

#endif // VECTOR2_H
