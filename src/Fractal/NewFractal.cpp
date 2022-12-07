#include "NewFractal.hpp"

NewFractal::NewFractal() {
    name = "Squared Diamond";
    num = 0;
    level = 10;

    size = 0.40 * ofGetHeight();
}

NewFractal::NewFractal(string name, int level, float size) : AbstractFractal(name, level) {
    this->size = size;
}

void NewFractal::draw(){
    //Increase and decrease levels of the fractal
    setNum(getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(0);
    }
    else if (getNum() > 20){
        setNum(20);
        setLevel(20);
    }
    draw((ofGetWidth())/2, ofGetHeight() / 4 - 0.4 * size, size, getNum(), 0);

    //determines the minimum and maximun of the level
    if (getLevel() == 1){
        min = true;
    }
    else{
        min = false;
    }
    if (getLevel() == 20){
        max = true;
    }
    else{
        max = false;
    }
}

void NewFractal::draw(float x, float y, float size, int n, float place) {
    //stops when the n is 0
    if (n == 0) {
        return;
    }
    //changes color of the levels
    if (n <= 1){
        ofSetColor(ofColor::lightBlue);
    }
    else if (n <= 4){
        ofSetColor(ofColor::yellow);
    }
    else{
        ofSetColor(ofColor::violet);
    }

    //place decides where to start to draw the lines, if place is 0 it will draw a diamond and if place is size it will draw a square
    if( place == 0){
        place = size;
    }
    else{
        place = 0;
    }
    //draws the lines to draw the shape
    ofDrawLine(x-place, y, (x + size), ((y + size)-place));
    ofDrawLine(x-place, y, (x - size),((y + size)+place));
    ofDrawLine((x - size), ((y + size)+place), (x+place), (y + (size*2)));
    ofDrawLine((x + size), ((y + size)-place), (x+place), (y + (size*2)));

    //updates the parameters of the recursion
    draw(x, y + 20, size - 20, n - 1, place);

}