#include "particle.h"
#include <iostream>

Particle::~Particle(){
    std::cout << "Particle's pure virtual destructor is called\n";
}