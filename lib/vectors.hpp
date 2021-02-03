#ifndef __VECTORS_HPP
#define __VECTORS_HPP

#include <cmath>
#include <iostream>

namespace math
{
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

        Vector(double magnitude, double direction[3])
        {

            Vector temp = Vector(direction).unit();
            Vector::x = temp.x * magnitude;
            Vector::y = temp.y * magnitude;
            Vector::z = temp.z * magnitude;
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

        // Build vector from magnitude and direction array.
        void build(double magnitude, double direction[3])
        {
            Vector unitv = unit();
            Vector::x = unitv.x * magnitude;
            Vector::y = unitv.y * magnitude;
            Vector::z = unitv.z * magnitude;
        }

        void print()
        {
            std::cout << "<" << Vector::x << ", " << Vector::y << ", " << Vector::z << ">" << std::endl;
        }

        Vector
        operator*(const Vector &v2)
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
} // namespace math

// class FrameVector : public Vector
// {
//     ReferenceFrame frame = ReferenceFrame('I');

//     using Vector::Vector;

//     void referenceFrame(ReferenceFrame *rframe)
//     {
//         this->frame = &rframe;
//     }
// };

// Math functions

double integrate(double dt, double y1, double y2)
{
    double ans = ((y1 + y2) * dt) / 2;
    return ans;
}
#endif