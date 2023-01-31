#ifndef NORMAL_H
#define NORMAL_H
#include "particle.h"
#include "simulation_properties.h"
#include <memory>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

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
        void change_attributes(Particle& particle) override;
        void change_attributes(Particle& particle, Simulation_properties& properties) override;
        void change_attributes(Positive& positive);
        void change_attributes(Negative& negative);
        const int id();
        // const int id() const;
        const float mass();
        // const float mass() const;
        const std::vector<float> position();
        // const std::vector<float> position() const;
        const std::vector<float> speed();
        // const std::vector<float> speed() const;
        virtual ~Normal();
};



#endif