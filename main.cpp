#include <iostream>
#include "./lib/dynamics.hpp"
int main()
{
    Vector v1 = Vector(1.7, 2.2, 3.93);
    Vector v2 = Vector(4, 5, 6);

    v1 = cross(v1, v2);
    std::cout << v1.x << "," << v1.y << "," << v1.z << std::endl;
}