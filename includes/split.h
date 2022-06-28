#ifndef SPLIT_H
#define SPLIT_H
#include "normal.h"
#include <utility>

class Split: public Normal{
    private:
        Particle *split();

    public:
        Split(int id, float mass, std::pair<float,float> &position, std::pair<float,float>& speed);
        ~Split();
        void change_attributes_after_hit(Particle & particle) override;
};


#endif