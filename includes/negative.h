#ifndef NEGATIVE_H
#define NEGATIVE_H
#include <utility>
#include "normal.h"

class Positive;

class Negative:public Normal { 
    public:
        Negative(int id, float mass, std::pair<float,float> & position, std::pair<float,float> & speed);
        ~Negative();
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
};

#endif
