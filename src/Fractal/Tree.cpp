#include "Tree.hpp"

Tree::Tree() {
    name = "Tree";
    num = 0;
    level = 10;
    
    length = 0.31 * ofGetHeight();
    rad = 1.5 * PI;
}

Tree::Tree(string name, int level, float length, float rad) : AbstractFractal(name, level) {
    this->length = length;
    this->rad = rad;
}

void Tree::draw(){
    vector <int> counter = {0, 0};
    setNum(getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(0);
    }
    else if (getNum() > 15){
        setNum(15);
        setLevel(15);
    }
    
    draw(ofGetWidth() / 2, ofGetHeight() - 20, getNum(), length, rad, counter);
    draw(ofGetWidth() / 4, ofGetHeight() - 20, getNum(), length / 4, rad, counter);
    draw(ofGetWidth() *3/4, ofGetHeight() - 20, getNum(), length / 4, rad, counter);

    if (getLevel() == 1){
        min = true;
    }
    else{
        min = false;
    }
    if (getLevel() == 15){
        max = true;
    }
    else{
        max = false;
    }
}

void Tree::draw(float x, float y, int n, float length, float rad, vector <int> counter) {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofSetColor(ofColor::green);
    if (n >= 4 && counter.at(0) <= 7){
        ofSetColor(ofColor::yellow);
        counter.at(0)++;
    }
    if (n > 4 && counter.at(1) <= 3){
        ofSetColor(ofColor::saddleBrown);
        counter.at(1)++;
    }
    if (getLevel() > 13){
        if (n <= 2){
            ofSetColor(ofColor::deepPink);
        }
    }
    
    ofDrawLine(x, y, x2, y2);

    draw(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI, counter);
    draw(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI, counter);
}