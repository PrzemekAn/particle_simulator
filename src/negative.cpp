#include "negative.h"

Negative::Negative(int id, float mass, std::vector<float> position, std::vector<float> speed):Normal(id, mass, position, speed){}

void Negative::change_attributes_after_hit(Particle & particle){

}

void Negative::change_attributes_after_hit(Positive & positive){

}

void Negative::change_attributes_after_hit(Negative & negative){

}

void Negative::change_attributes(Particle& particle){
    
}

Negative::~Negative() = default;