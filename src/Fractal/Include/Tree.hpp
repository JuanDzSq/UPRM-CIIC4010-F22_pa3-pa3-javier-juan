#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class Tree : public AbstractFractal {
  private:
    float length;
    float rad;
    
  public:
    Tree();
    Tree(string name, int level, float length, float rad);

    void draw();
    void draw(float x, float y, int n, float length, float rad, vector <int> counter);

    //Getters
    float getLength() {return length;};
    float getRad() {return rad;};
    
    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};
    bool getIsMax() {return max;}
    bool getIsMin() {return min;}

    //Setters
    void setLength(float length) {this->length = length;};
    void setRad(float rad) {this->rad = rad;};

    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};