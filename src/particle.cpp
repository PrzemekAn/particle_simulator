#include "particle.h"
#include <iostream>

void Particle::change_attributes_after_hit(Positive & positive_particle){
    change_attributes_after_hit(positive_particle);
}

void Particle::change_attributes_after_hit(Negative & negative_particle){
    change_attributes_after_hit(negative_particle);
}

void Particle::change_attributes(Positive & poisitive_particle){
    change_attributes(poisitive_particle);
}

void Particle::change_attributes(Negative & negative_particle){
    change_attributes(negative_particle);
}

Particle::~Particle(){
    // std::cout << "Particle's pure virtual destructor is called\n";
}
