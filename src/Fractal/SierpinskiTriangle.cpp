#include "SierpinskiTriangle.hpp"

SierpinskiTriangle::SierpinskiTriangle() {
    name = "Sierpinski Triangle";
    num = 0;
    level = 0;

    size = 0.88 * ofGetHeight();
}

SierpinskiTriangle::SierpinskiTriangle(string name, int level, float size) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
    this->size = size;
}

void SierpinskiTriangle::draw(){
        setNum(7 + getLevel());
        if (getNum() < 0){
            setNum(0);
            setLevel(-7);
        }
        else if (getNum() > 12){
            setNum(12);
            setLevel(5);
        }
        draw((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, getNum());
}

void SierpinskiTriangle::draw(float x, float y, float size, int n) {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    draw(x, y, size / 2, n - 1);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    draw((a.x + c.x) / 2, (((a.y + b.y) / 2) + c.y) / 2, size / 2, n - 1);
}