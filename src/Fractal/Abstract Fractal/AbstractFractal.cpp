#include <AbstractFractal.h>

AbstractFractal::AbstractFractal(){
}

AbstractFractal::AbstractFractal(string name, int level){
    this->name = name;
    this->level = level;
}

void AbstractFractal::draw(){
}