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

};