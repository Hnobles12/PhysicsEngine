#ifndef __DYNAMICS_HPP
#define __DYNAMICS_HPP
#include "./vectors.hpp"

const int MAX_FRAMES = 5; // Maximum number of frames available for vector transport.

// class FrameRelation
// {
// public:
//     ReferenceFrame frame;
//     Vector rotation;

//     FrameRelation(ReferenceFrame frame, Vector rotation)
//     {
//         this->frame = frame;
//         this->rotation = rotation;
//     }
// };

// typedef struct FrameRelation
// {
//     char frame_name;
//     Vector rotation;
// } FrameRelation;

// class ReferenceFrame
// {
// private:
//     FrameRelation relations[MAX_FRAMES];
//     int relations_count = 0;

// public:
//     char name;
//     ReferenceFrame(char name)
//     {
//         this->name = name;
//     }

//     void angularVelocity(ReferenceFrame frame, Vector rotation)
//     {
//         if ((this->relations_count > MAX_FRAMES))
//         {
//             return;
//         }
//         FrameRelation new_frame = {
//             .frame_name = frame.name,
//             .rotation = rotation};
//         this->relations[relations_count] = new_frame;
//         this->relations_count++;
//     }

//     Vector rotation(ReferenceFrame frame)
//     {
//         for (int i = 0; i < MAX_FRAMES; i++)
//         {
//             if (frame.name == this->relations[i].frame_name)
//             {
//                 return this->relations[i].rotation;
//             }
//         }
//         return Vector(0, 0, 0);
//     }
// };

namespace physics
{

    typedef struct FrameRelation
    {
        char frame_name;
        math::Vector rotation;
    } FrameRelation;

    class ReferenceFrame
    {
    private:
        FrameRelation relations[MAX_FRAMES];
        int relations_count = 0;

    public:
        char name;
        ReferenceFrame(char name)
        {
            this->name = name;
        }

        void angularVelocity(ReferenceFrame frame, math::Vector rotation)
        {
            if ((this->relations_count > MAX_FRAMES))
            {
                return;
            }
            FrameRelation new_frame = {
                .frame_name = frame.name,
                .rotation = rotation};
            this->relations[relations_count] = new_frame;
            this->relations_count++;
        }

        math::Vector rotation(ReferenceFrame frame)
        {
            for (int i = 0; i < MAX_FRAMES; i++)
            {
                if (frame.name == this->relations[i].frame_name)
                {
                    return this->relations[i].rotation;
                }
            }
            return math::Vector(0, 0, 0);
        }
    };

    class Vector : math::Vector
    {
    public:
        ReferenceFrame frame = ReferenceFrame('I');

        using math::Vector::Vector;

        void referenceFrame(ReferenceFrame rframe)
        {
            this->frame = rframe.name;
        }

        void operator=(math::Vector *vector)
        {
            this->x = vector->x;
            this->y = vector->y;
            this->z = vector->z;
        }
    };
} // namespace physics
#endif