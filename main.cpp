#include <iostream>
#include "./lib/dynamics.hpp"
int main()
{
    Vector v1 = Vector(1, 2, 3);
    Vector v2 = Vector(2, 2, 2);

    v1 *= v2;
    double vdir[] = {0, 0, -1};
    Force f = Force();
    f.build(100.0, vdir);
    // f = f * v1;
    std::cout
        << f.x << "," << f.y << "," << f.z << std::endl;
}