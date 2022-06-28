#ifndef ANTIMATER_H
#define ANTIMATER_H
#include "normal.h"
#include <utility>

class Antimater: public Normal
{
    private:
        void substract_mass_from_particle(Particle& particle);

    public:
        Antimater(int id, float mass, std::pair<float,float>&position, std::pair<float,float> &speed);
        ~Antimater();
        void change_attributes_after_hit(Particle & particle) override;
};

#endif