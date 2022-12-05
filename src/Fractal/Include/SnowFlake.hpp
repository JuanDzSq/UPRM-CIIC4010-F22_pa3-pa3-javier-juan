#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake : public AbstractFractal {
  private:
    glm::vec2 start;
    glm::vec2 end;
    float size;
    // string name;
    // int level;
    // int num;
    
  public:
    SnowFlake();
    SnowFlake(string name, int level, float size, glm::vec2 start, glm::vec2 end);

    void draw();
    void draw(int n, SnowFlake *flake);

    //Getters
    glm::vec2 getStart() const { return start; };
    glm::vec2 getEnd() const { return end; };
    glm::vec2 getA();
    glm::vec2 getB();
    glm::vec2 getC();
    glm::vec2 getD();
    glm::vec2 getE();

    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};
    bool getIsMax() {return max;}
    bool getIsMin() {return min;}
    
    //Setters
    void setStart(glm::vec2 start) { this->start = start; };
    void setEnd(glm::vec2 end) { this->end = end; };

    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};