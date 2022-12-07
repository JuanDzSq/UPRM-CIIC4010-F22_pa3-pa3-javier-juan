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

    //Setters
    void setSize(float size) {this->size = size;};
};