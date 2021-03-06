#ifndef PARTICLE_H
#define PARTICLE_H
#include<utility>

class Particle{
    public:
        virtual void change_attributes_after_hit(Particle&) = 0;
        virtual int get_id() = 0;
        virtual float get_mass() = 0;
        virtual std::pair<float,float> get_position() = 0;
        virtual std::pair<float,float> get_speed() = 0;
        virtual ~Particle() = 0;
};

#endif
