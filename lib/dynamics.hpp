#ifndef __DYNAMICS_HPP
#define __DYNAMICS_HPP

#include <cmath>

class Vector
{
public:
    float x;
    float y;
    float z;

    Vector(float x, float y, float z)
    {
        Vector::x = x;
        Vector::y = y;
        Vector::z = z;
    }

    float mag()
    {
        float mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        return mag;
    }
};

Vector cross(Vector v1, Vector v2)
{
    Vector temp = Vector(0, 0, 0);
    temp.x = (v1.y * v2.z) - (v1.z * v2.y);
    temp.y = (v1.z * v2.x) - (v1.x * v2.z);
    temp.z = (v1.x * v2.y) - (v1.y * v2.x);

    return temp;
}

#endif