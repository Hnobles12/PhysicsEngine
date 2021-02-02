#ifndef __PHYSICS_HPP
#define __PHYSICS_HPP
#include "dynamics.hpp"

class Environment
{
public:
    float G = -9.81; //m/s^2
    Vector g = Vector(0, 0, G);

    Environment()
    {
    }
};

class Body
{
public:
    // Body Attributes
    float mass; // Mass of Body

    //Moments of Inertia
    float Ixx;
    float Iyy;
    float Izz;
    float Ixy;
    float Ixz;
    float Iyz;

    // Body Forces

    // Body Dynamics
    Vector velocity = Vector(0, 0, 0);

    Body(float mass, float I[6], float BBOX[3])
    {
        Body::mass = mass;
    }

    float linearEOM()
    {
    }

    void update(float dt)
    {
    }
};

#endif
