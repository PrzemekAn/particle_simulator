#ifndef POSITIVE_H
#define POSITIVE_H
#include <vector>
#include "normal.h"

class Negative;

class Positive: public Normal{
    public:
        Positive(int id, float mass, std::vector<float> position, std::vector<float> speed);
        ~Positive();
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
        void change_attributes(Particle& particle) override;
};

#endif