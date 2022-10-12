#ifndef PARTICLE_H
#define PARTICLE_H
#include <vector>
#include <memory>

class Positive;
class Negative;

class Particle{
    public:
        virtual void change_attributes_after_hit(Particle& particle) = 0;
        virtual void change_attributes_after_hit(Positive& poisitive_particle);
        virtual void change_attributes_after_hit(Negative& negative_particle);
        virtual const int get_id() = 0;
        virtual const float get_mass() = 0;
        virtual const std::vector<float> get_position() = 0;
        virtual const std::vector<float> get_speed() = 0;
        virtual ~Particle();
};

using Particle_uptr = std::unique_ptr<Particle>;

#endif
