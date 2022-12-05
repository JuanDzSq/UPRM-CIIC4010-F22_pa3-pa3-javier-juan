#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class Circle : public AbstractFractal {
  private:
    float r;
    float angle = 0;
    ofColor color;
    
  public:
    Circle();
    Circle(string name, int level, float r, float angle);

    void draw();
    void draw(float x, float y, float r, int n, ofColor color);

    //Getters
    float getRadius() {return r;};
    float getAngle() {return angle;};
    
    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};

    //Setters
    void setRadius(float r) {this->r = r;};
    void setAngle(float angle) {this->angle = angle;};

    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};