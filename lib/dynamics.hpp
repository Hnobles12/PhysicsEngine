#ifndef __DYNAMICS_HPP
#define __DYNAMICS_HPP

#include <cmath>

class Vector
{
public:
    double x;
    double y;
    double z;

    Vector(double x = 0, double y = 0, double z = 0)
    {
        Vector::x = x;
        Vector::y = y;
        Vector::z = z;
    }

    Vector(double vector[3])
    {
        Vector::x = vector[0];
        Vector::y = vector[1];
        Vector::z = vector[2];
    }

    double mag()
    {
        double mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        return mag;
    }

    Vector unit()
    {
        Vector v = Vector(Vector::x, Vector::y, Vector::z);
        double mag = v.mag();
        v.x = v.x / mag;
        v.y = v.y / mag;
        v.z = v.z / mag;
        return v;
    }

    void dot(Vector v)
    {
        Vector::x = v.x * Vector::x;
        Vector::y = v.x * Vector::y;
        Vector::z = v.x * Vector::z;
    }

    void build(double magnitude, double direction[3])
    {
        Vector::x = direction[0];
        Vector::y = direction[1];
        Vector::z = direction[2];

        Vector unitv = unit();
        Vector::x = unitv.x * magnitude;
        Vector::y = unitv.y * magnitude;
        Vector::z = unitv.z * magnitude;
    }

    Vector operator*(const Vector &v2)
    {
        Vector temp = Vector();
        temp.x = Vector::x * v2.x;
        temp.y = Vector::y * v2.y;
        temp.z = Vector::z * v2.z;
        return temp;
    }
    Vector operator*=(const Vector &v2)
    {
        Vector::x *= v2.x;
        Vector::y *= v2.y;
        Vector::z *= v2.z;
    }

    Vector operator*(const double scalar)
    {
        Vector temp = Vector();
        temp.x = Vector::x * scalar;
        temp.y = Vector::y * scalar;
        temp.z = Vector::z * scalar;
        return temp;
    }
    Vector operator*=(const double scalar)
    {
        Vector::x *= scalar;
        Vector::y *= scalar;
        Vector::z *= scalar;
    }

    Vector operator+(const Vector &v2)
    {
        Vector temp = Vector();
        temp.x = Vector::x + v2.x;
        temp.y = Vector::y + v2.y;
        temp.z = Vector::z + v2.z;
        return temp;
    }

    Vector operator+=(const Vector &v2)
    {
        Vector::x += v2.x;
        Vector::y += v2.y;
        Vector::z += v2.z;
    }
};

class Force : public Vector
{
public:
    double mag; // Force Magnitude
    Vector dir; // Force Direction
    Vector vec; // Force Vector

    // Force(double mag, Vector dir)
    // {
    //     Force::dir = dir.unit();
    //     Force::vec = Force::dir * mag;
    // }
};

// Math functions
Vector cross(Vector v1, Vector v2)
{
    Vector temp = Vector(0, 0, 0);
    temp.x = (v1.y * v2.z) - (v1.z * v2.y);
    temp.y = (v1.z * v2.x) - (v1.x * v2.z);
    temp.z = (v1.x * v2.y) - (v1.y * v2.x);

    return temp;
}

Vector dot(Vector v1, Vector v2)
{
    Vector v = Vector(0, 0, 0);
    v.x = v1.x * v2.x;
    v.y = v1.x * v2.y;
    v.z = v1.x * v2.z;
    return v;
}

double integrate(double dt, double y1, double y2)
{
    double ans = ((y1 + y2) * dt) / 2;
    return ans;
}
#endif