#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class Circle : public AbstractFractal {
  private:
    float r;
    float angle = 0;
    
  public:
    Circle();
    Circle(string name, int level, float r, float angle);

    void draw();
    void draw(float x, float y, float r, int n);

    //Getters
    float getRadius() {return r;};
    float getAngle() {return angle;};

    //Setters
    void setRadius(float r) {this->r = r;};
    void setAngle(float angle) {this->angle = angle;};
};