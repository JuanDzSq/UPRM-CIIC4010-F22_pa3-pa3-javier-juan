#pragma once
#include <string>

using namespace std;

class Fractal {
    public:
        virtual void draw() = 0;
        virtual string getName() = 0;
        virtual int getLevel() = 0;

};