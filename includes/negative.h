#ifndef NEGATIVE_H
#define NEGATIVE_H
#include <vector>
#include "normal.h"

class Positive;

class Negative:public Normal { 
    public:
        Negative(int id, float mass, std::vector<float> position, std::vector<float> speed);
        ~Negative();
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
        void change_attributes() override;
};

#endif
