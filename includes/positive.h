#ifndef POSITIVE_H
#define POSITIVE_H
#include <utility>
#include "normal.h"

class Negative;

class Positive: public Normal{
    public:
        Positive(int id, float mass, std::pair<float,float> &position, std::pair<float,float>& speed);
        ~Positive();
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
};

#endif