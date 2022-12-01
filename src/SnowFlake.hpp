#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.h"
#include <string>

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake : public AbstractFractal {
  private:
    glm::vec2 start;
    glm::vec2 end;
    // string name;
    // int level;
    // int num;
  public:
    SnowFlake();
    SnowFlake(string name, int level, int num, glm::vec2 start, glm::vec2 end);

    glm::vec2 getStart() const { return start; }
    glm::vec2 getEnd() const { return end; }
    void setStart(glm::vec2 start) { this->start = start; }
    void setEnd(glm::vec2 end) { this->end = end; }

    void draw();
    void draw(int n, SnowFlake *flake);

    glm::vec2 getA();
    glm::vec2 getB();
    glm::vec2 getC();
    glm::vec2 getD();
    glm::vec2 getE();

    //Getters
    string getName(){return name;};
    int getLevel(){return level;};
    int getNum(){return num;};
    
    //Setters
    void setNum(int num){this->num = num;};
    void setLevel(int level){this->level = level;};
};