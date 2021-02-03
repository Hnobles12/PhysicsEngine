#include <iostream>
#include "./lib/dynamics.hpp"
#include "./lib/vectors.hpp"

int main()
{
    double direction[] = {1.0, 0, 0};
    math::Vector v1 = math::Vector(4, direction);

    physics::ReferenceFrame I = physics::ReferenceFrame('I');
    physics::ReferenceFrame A = physics::ReferenceFrame('A');
    A.angularVelocity(I, v1);

    A.rotation(I).print();

    physics::Vector force = physics::Vector(0.0, 0.0, 0.0);
    force.referenceFrame(A);

    std::cout
        << force.frame.name << std::endl;

    // std::cout << A.rotation(I).print() << std::endl;
}