#include "positive.h"

Positive::Positive(int id, float mass, std::pair<float,float> &position, std::pair<float,float>&speed): Normal(id, mass, position, speed){};


void Positive::change_attributes_after_hit(Particle& particle){

}

void Positive::change_attributes_after_hit(Positive & positive){

}

void Positive::change_attributes_after_hit(Negative & negative){

}

Positive::~Positive() = default;