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
    if (n == 0) {
        return;
    }

    if (n <= 1){
        ofSetColor(ofColor::lightBlue);
    }
    else if (n <= 4){
        ofSetColor(ofColor::yellow);
    }
    else{
        ofSetColor(ofColor::violet);
    }


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

    draw(x, y + 20, size - 20, n - 1, place);

}