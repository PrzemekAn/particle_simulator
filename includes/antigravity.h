#ifndef ANTIGRAVITY_H
#define ANTIGRAVITY_H
#include "normal.h"
#include <utility>

class Antigravity: public Normal{
    public:
        Antigravity(int id, float mass, std::pair<float,float> &position, std::pair<float,float> & speed);
        ~Antigravity();
        void change_attributes_after_hit(Particle& particle) override;
};

#endif