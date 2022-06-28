#include "antigravity.h"


Antigravity::Antigravity(int id, float mass, std::pair<float,float>& position, std::pair<float,float>& speed): Normal(id, mass, position, speed){}

void Antigravity::change_attributes_after_hit(Particle & particle){

}

Antigravity::~Antigravity() = default;