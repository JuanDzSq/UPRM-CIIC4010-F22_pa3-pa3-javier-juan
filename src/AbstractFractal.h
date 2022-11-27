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
    int level;

public:
    //constructor
    AbstractFractal();
    AbstractFractal(string name, int level, float x, float y, int n);
    //getters
    float getX() { return x; }
    float getY() { return y; }
    int getN() { return n; }
    string getName() { return name; };
    int getLevel() { return level; };
    //setters
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setN(float n) { this->n = n; }
    //methods
    virtual void draw() = 0;
};