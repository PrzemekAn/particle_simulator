#include "positive.h"

Positive::Positive(int id, float mass, std::vector<float> position, std::vector<float> speed): Normal(id, mass, position, speed){};


void Positive::change_attributes_after_hit(Particle& particle){

}

void Positive::change_attributes_after_hit(Positive & positive){

}

void Positive::change_attributes_after_hit(Negative & negative){

}

Positive::~Positive() = default;