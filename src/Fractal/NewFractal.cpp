#include "NewFractal.hpp"

NewFractal::NewFractal() {
    name = "Squared Diamond";
    num = 0;
    level = 0;

    size = 0.40 * ofGetHeight();
}

NewFractal::NewFractal(string name, int level, float size) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
    this->size = size;
}

void NewFractal::draw(){
    setNum(7 + getLevel());
        if (getNum() < 0){
            setNum(0);
            setLevel(-7);
        }
        else if (getNum() > 20){
            setNum(20);
            setLevel(13);
        }
        draw((ofGetWidth())/2, ofGetHeight() / 4 - 0.4 * size, size, getNum(), 0);
}

void NewFractal::draw(float x, float y, float size, int n, float place) {
    if (n == 0) {
        return;
    }

    // ofPoint a(x, y);
    // ofPoint b(x + size, y);
    // ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    // ofPoint a(x, y);
    // ofPoint b(x + size / 2, y + ((sqrt(3) * size) / 2));
    // ofPoint c(x - size / 2, y + ((sqrt(3) * size) / 2));

    // ofPoint d(x + size + size / 2, y + ((sqrt(3) * size) / 2));
    // ofPoint e(x + size / 2, y + ((sqrt(3) * size) / 2));
    // ofPoint f((x + size / 2) + size/2, (y + ((sqrt(3) * size) / 2)) + size);

    // ofPoint g(x - size - size / 2, y + ((sqrt(3) * size) / 2));
    // ofPoint h(x - size / 2, y + ((sqrt(3) * size) / 2));
    // ofPoint i((x - size / 2) - size/2, (y + ((sqrt(3) * size) / 2)) + size);

    // ofPoint a(x, y);
    // ofPoint b(x + size/3, y + size);
    // ofPoint c(x - size/3, y + size);

    // ofPoint d(x + size/3, y + size);
    // ofPoint e((x + size/3) + size, y + size);
    // ofPoint f((x + size/3) + size/4, (y + size) + size/3 + size/3);

    // ofPoint g(x - size/3, y + size);
    // ofPoint h((x - size/3) - size, y + size);
    // ofPoint i((x - size/3) - size/4, (y + size) + size/3*2);

    // ofPoint j((x - size/3) - size/4, (y + size) + size/3*2);
    // ofPoint k(x, ((y + size) + size));
    // ofPoint l((x - size/3) - size/2, (y + size) + size + size/3);

    // ofPoint m((x + size/3) + size/4, (y + size) + size/3*2);
    // ofPoint o(x, ((y + size) + size));
    // ofPoint p((x + size/3) + size/2, (y + size) + size + size/3);



    // ofDrawLine(x, y, x + size*2, y + size*3);
    // ofDrawLine(x + size*2, y + size*3, x - size*2, y + size);
    // ofDrawLine(x - size*2, y + size, x + size*2, y + size);
    // ofDrawLine(x + size*2, y + size, x - size*2, y + size*3);
    // ofDrawLine(x - size*2, y + size*3, x, y);

    if( place == 0){
        place = size;
    }
    else{
        place = 0;
    }

    ofDrawLine(x-place, y, (x + size), ((y + size)-place));
    ofDrawLine(x-place, y, (x - size),((y + size)+place));
    ofDrawLine((x - size), ((y + size)+place), (x+place), (y + (size*2)));
    ofDrawLine((x + size), ((y + size)-place), (x+place), (y + (size*2)));

    



    // ofDrawTriangle(a, b, c);
    // ofDrawTriangle(d, e, f);
    // ofDrawTriangle(g, h, i);
    // ofDrawTriangle(j, k, l);
    // ofDrawTriangle(m, o, p);

    draw(x, y + 20, size - 20, n - 1, place);
    // draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    // draw((a.x + c.x) / 2, (((a.y + b.y) / 2) + c.y) / 2, size / 2, n - 1);
}