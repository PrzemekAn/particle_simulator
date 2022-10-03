#include "antigravity.h"


Antigravity::Antigravity(int id, float mass, std::vector<float> position, std::vector<float> speed): Normal(id, mass, position, speed){}

void Antigravity::change_attributes_after_hit(Particle & particle){

}

Antigravity::~Antigravity() = default;