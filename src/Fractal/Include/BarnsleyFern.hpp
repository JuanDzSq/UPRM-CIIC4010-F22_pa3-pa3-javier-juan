#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class BarnsleyFern : public AbstractFractal {
  private:

  public:
    BarnsleyFern();
    BarnsleyFern(string name, int level);

    void draw();
    void draw(float x, float y, float n);

    //Getters
    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};

    //Setters
    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};