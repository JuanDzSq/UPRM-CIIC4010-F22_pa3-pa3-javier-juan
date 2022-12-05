#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class SierpinskiTriangle : public AbstractFractal {
  private:
    float size;

  public:
    SierpinskiTriangle();
    SierpinskiTriangle(string name, int level, float size);

    void draw();
    void draw(float x, float y, float size, int n);

    //Getters
    float getSize() {return size;};

    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};
    bool getIsMax() {return max;}
    bool getIsMin() {return min;}

    //Setters
    void setSize(float size) {this->size = size;};

    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};