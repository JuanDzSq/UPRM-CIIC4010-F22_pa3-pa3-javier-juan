#include <AbstractFractal.h>

AbstractFractal::AbstractFractal(){
}

AbstractFractal::AbstractFractal(string name, int level, float x, float y, int n){
    this->name = name;
    this->level = level;
    this->x = x;
    this->y = y;
    this->n = n;
}

void AbstractFractal::draw(){
}