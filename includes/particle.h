#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <memory>


class Particle{
    public:
        virtual void change_attributes_after_hit(Particle&) = 0;
        virtual const int get_id() = 0;
        virtual const float get_mass() = 0;
        virtual const std::vector<float> get_position() = 0;
        virtual const std::vector<float> get_speed() = 0;
        virtual ~Particle();
};

using Particle_uptr = std::unique_ptr<Particle>;

#endif
