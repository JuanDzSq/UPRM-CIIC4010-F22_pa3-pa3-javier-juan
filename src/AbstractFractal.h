#pragma once
#include <Fractal.h>
#include <string>

using namespace std;

class AbstractFractal : public Fractal
{
protected:
    float x;
    float y;
    int n;
    string name;
    int level = 0;
    int num = 0;

public:
    //Constructor
    AbstractFractal();
    AbstractFractal(string name, int level, int num);

    //Getters
    virtual float getX() { return x; }
    virtual float getY() { return y; }
    virtual int getN() { return n; }
    virtual string getName() { return name; }
    virtual int getLevel() { return level; }
    virtual int getNum() { return num; }

    //Setters
    virtual void setX(float x) { this->x = x; }
    virtual void setY(float y) { this->y = y; }
    virtual void setN(float n) { this->n = n; }
    virtual void setLevel(int level){this->level = level;}
    virtual void setNum(int num){this->num = num;}

    //Methods
    virtual void draw() = 0;
};