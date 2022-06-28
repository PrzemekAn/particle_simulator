#include "split.h"

Split::Split(int id, float mass, std::pair<float,float>&position, std::pair<float,float>&speed): Normal(id, mass, position, speed){}

Split::~Split() = default;

void Split::change_attributes_after_hit(Particle & particle){}

Particle * Split::split(){
    //temporary fixed numbers
    int id{10};
    float mass{10.2};
    std::pair<float,float> position{10.2,10.3};
    std::pair<float,float> speed{10.2,10.3};
    Normal * normal = new Normal(id, mass, position, speed);
    return normal;
}