#include "SierpinskiTriangle.hpp"

SierpinskiTriangle::SierpinskiTriangle() {
    name = "Sierpinski Triangle";
    num = 0;
    level = 7;

    size = 0.88 * ofGetHeight();
}

SierpinskiTriangle::SierpinskiTriangle(string name, int level, float size) : AbstractFractal(name, level) {
    this->size = size;
}

void SierpinskiTriangle::draw(){
    //Increase and decrease levels of the fractal
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

    //determines the minimum and maximun of the level
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
    //it will stop when n is 0
    if (n == 0) {
        return;
    }
    //changes the colors of the levels
    if (n <= 1){
        ofSetColor(237, 295, 12);
    }
    else if (n <= 4){
        ofSetColor(237, 181, 12);
    }
    else{
        ofSetColor(237, 155, 12);
    }
    //creates the points that are used to draw the triangle
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));
    ofDrawTriangle(a, b, c);

    ofFill();
    //updates the parameters 
    draw(a.x, a.y, size / 2, n - 1);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    draw((a.x + c.x) / 2, (((a.y + b.y) / 2) + c.y) / 2, size / 2, n - 1);
}