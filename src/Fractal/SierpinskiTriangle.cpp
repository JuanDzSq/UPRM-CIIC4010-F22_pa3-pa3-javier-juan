#include "SierpinskiTriangle.hpp"

SierpinskiTriangle::SierpinskiTriangle() {
    name = "Sierpinski Triangle";
    num = 0;
    level = 7;

    size = 0.88 * ofGetHeight();
}

SierpinskiTriangle::SierpinskiTriangle(string name, int level, float size) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
    this->size = size;
}

void SierpinskiTriangle::draw(){
    setNum(getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(0);
    }
    else if (getNum() > 8){
        setNum(8);
        setLevel(8);
    }
    draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, getNum());

    if (getLevel() == 1){
        min = true;
    }
    else{
        min = false;
    }
    if (getLevel() == 8){
        max = true;
    }
    else{
        max = false;
    }
}

void SierpinskiTriangle::draw(float x, float y, float size, int n) {
    if (n == 0) {
        return;
    }

    if (n <= 1){
        ofSetColor(237, 295, 12);
    }
    else if (n <= 4){
        ofSetColor(237, 181, 12);
    }
    else{
        ofSetColor(237, 155, 12);
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));
    ofDrawTriangle(a, b, c);

    ofFill();
    draw(a.x, a.y, size / 2, n - 1);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    draw((a.x + c.x) / 2, (((a.y + b.y) / 2) + c.y) / 2, size / 2, n - 1);
}