#include "negative.h"

Negative::Negative(int id, float mass, std::pair<float,float> & position, std::pair<float,float> & speed):Normal(id, mass, position, speed){}

void Negative::change_attributes_after_hit(Particle & particle){

}

void Negative::change_attributes_after_hit(Positive & positive){

}

void Negative::change_attributes_after_hit(Negative & negative){

}

Negative::~Negative() = default;