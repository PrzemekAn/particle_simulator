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
        std::unique_ptr<Particle> split();
        void substract_mass_from_particle(Particle& particle); 

    protected:
        int m_id{0};
        float m_mass{0};
        std::vector<float> m_position{0,0};
        std::vector<float> m_speed{0,0};

    public:
        Normal(int id, float mass, std::vector<float> position, std::vector<float> speed);
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
        int get_id();
        float get_mass();
        std::vector<float> get_position();
        std::vector<float> get_speed();
        int give_the_id();
        ~Normal();
};



#endif