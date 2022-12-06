#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

class NewFractal : public AbstractFractal {
    private:
        float size;
    public:
        NewFractal();
        NewFractal(string name, int level, float size);

        void draw();
        void draw(float x, float y, float size, int n, float place);
};