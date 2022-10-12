#include "particle.h"
#include <iostream>

void Particle::change_attributes_after_hit(Positive & poisitive_particle){
    change_attributes_after_hit(poisitive_particle);
}

void Particle::change_attributes_after_hit(Negative & negative_particle){
    change_attributes_after_hit(negative_particle);
}

Particle::~Particle(){
    // std::cout << "Particle's pure virtual destructor is called\n";
}
