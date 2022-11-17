#include "split.h"

Split::Split(int id, float mass, std::vector<float> position, std::vector<float> speed): Normal(id, mass, position, speed){}

Split::~Split() = default;

void Split::change_attributes_after_hit(Particle & particle){}

void Split::change_attributes(){
    
}

std::unique_ptr<Particle> Split::split(){
    //temporary fixed numbers
    int id{10};
    float mass{10.2};
    std::vector<float> position{10.2,10.3};
    std::vector<float> speed{10.2,10.3};
    std::unique_ptr<Particle> normal (new Normal(id, mass, position, speed));
    return normal;
}