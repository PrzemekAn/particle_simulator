#ifndef NORMAL_H
#define NORMAL_H
#include "particle.h"
#include <memory>
#include <vector>
#include <iostream>

class Positive;
class Negative;

class Normal:public Particle{
    private:
        Particle_uptr split();
        void substract_mass_from_particle(Particle& particle); 

    protected:
        int m_id;
        float m_mass;
        std::vector<float> m_position;
        std::vector<float> m_speed;

    public:
        Normal(int id, float mass, std::vector<float> position, std::vector<float> speed);
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
        const int get_id();
        const float get_mass();
        const std::vector<float> get_position();
        const std::vector<float> get_speed();
        int give_the_id();
        ~Normal();
};



#endif