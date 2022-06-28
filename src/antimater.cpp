#include "antimater.h"

Antimater::Antimater(int id, float mass, std::pair<float,float>&position, std::pair<float,float>&speed): Normal(id, mass, position, speed){}

Antimater::~Antimater() = default;

void Antimater::change_attributes_after_hit(Particle& Particle){}

void Antimater::substract_mass_from_particle(Particle& particle){}