#ifndef ANTIMATER_H
#define ANTIMATER_H
#include "normal.h"
#include <vector>

class Antimater: public Normal
{
    private:
        void substract_mass_from_particle(Particle& particle);

    public:
        Antimater(int id, float mass, std::vector<float> position, std::vector<float> speed);
        ~Antimater();
        void change_attributes_after_hit(Particle & particle) override;
        void change_attributes() override;
};

#endif