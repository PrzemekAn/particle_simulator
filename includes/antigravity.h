#ifndef ANTIGRAVITY_H
#define ANTIGRAVITY_H
#include "normal.h"
#include <vector>

class Antigravity: public Normal{
    public:
        Antigravity(int id, float mass, std::vector<float> position, std::vector<float> speed);
        ~Antigravity();
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes(Particle& particle) override;
};

#endif