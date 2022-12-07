#pragma once
#include <string>

using namespace std;

class Fractal {
    public:
        virtual void draw() = 0;

        //Getters
        virtual string getName() = 0;
        virtual int getLevel() = 0;
        virtual int getNum() = 0;
        virtual bool getIsMax() = 0;
        virtual bool getIsMin() = 0;

        //Setters
        virtual void setLevel(int level) = 0;
        virtual void setNum(int num) = 0;

};