#ifndef NORMAL_H
#define NORMAL_H
#include <utility>
#include "particle.h"

class Positive;
class Negative;

class Normal:public Particle{
    private:
        Particle split();
        void substract_mass_from_particle(Particle& particle); 

    protected:
        int m_id{0};
        float m_mass{0};
        std::pair<float,float> m_position{0,0};
        std::pair<float,float> m_speed{0,0};

    public:
        Normal(int id, float mass, std::pair<float,float>& position, std::pair<float,float>&speed);
        void change_attributes_after_hit(Particle& particle) override;
        void change_attributes_after_hit(Positive& positive);
        void change_attributes_after_hit(Negative& negative);
        int get_id();
        float get_mass();
        std::pair<float,float> get_position();
        std::pair<float,float> get_speed();
        int give_the_id();
        ~Normal();
};



#endif