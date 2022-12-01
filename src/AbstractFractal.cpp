#include <AbstractFractal.h>

AbstractFractal::AbstractFractal(){
}

AbstractFractal::AbstractFractal(string name, int level, int num){
    this->name = name;
    this->level = level;
    this->num = num;
}

void AbstractFractal::draw(){
}