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
        virtual void change_attributes(Particle& particle) = 0;
        virtual void change_attributes(Positive& poisitive_particle);
        virtual void change_attributes(Negative& negative_particle);
        virtual const int id() = 0;
        // virtual const int id() const = 0;
        virtual const float mass() = 0;
        // virtual const float mass() const = 0;
        virtual const std::vector<float> position() = 0;
        // virtual const std::vector<float> position() const = 0;
        virtual const std::vector<float> speed() = 0;
        // virtual const std::vector<float> speed() const = 0;
        virtual ~Particle();
};

using Particle_uptr = std::unique_ptr<Particle>;

#endif
