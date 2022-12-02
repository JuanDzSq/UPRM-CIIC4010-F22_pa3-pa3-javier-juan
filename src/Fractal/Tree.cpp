#include "Tree.hpp"

Tree::Tree() {
    name = "Tree";
    num = 0;
    level = 0;
    
    length = 0.31 * ofGetHeight();
    rad = 1.5 * PI;
}

Tree::Tree(string name, int level, float length, float rad) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
    this->length = length;
    this->rad = rad;
}

void Tree::draw(){
    setNum(10 + getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(-10);
    }
    else if (getNum() > 16){
        setNum(16);
        setLevel(6);
    }
    draw(ofGetWidth() / 2, ofGetHeight() - 20, getNum(), length, rad);
    draw(ofGetWidth() * 19 / 20, ofGetHeight() - 20, 10, length / 2, rad);
    draw(ofGetWidth() / 20, ofGetHeight() - 20, 10, length / 2, rad):
}

void Tree::draw(float x, float y, int n, float length, float rad) {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);

    draw(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
    draw(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
}