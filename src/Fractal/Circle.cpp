#include "Circle.hpp"

Circle::Circle() {
    name = "Circle";
    num = 0;
    level = 3;

    r = 0.31 * ofGetHeight();
}

Circle::Circle(string name, int level, float r, float angle) : AbstractFractal(name, level) {
    this->r = r;
    this->angle = angle;
}

void Circle::draw(){
    angle += 0.01;
     //Increase and decrease levels of the fractal
    setNum(getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(0);
    }
    else if (getNum() > 6){
        setNum(6);
        setLevel(6);
    }
    draw(ofGetWidth() / 2, ofGetHeight() / 2, r, getNum());

    //determines the minimum and maximun of the level
    if (getLevel() == 1){
        min = true;
    }
    else{
        min = false;
    }
    if (getLevel() == 6){
        max = true;
    }
    else{
        max = false;
    }
}

void Circle::draw(float x, float y, float r, int n) {
    //stops when the n is 0
    if (n == 0) return;
    
    //changes colors of the levels
    if (n <= 2){
        ofSetColor(ofColor::yellow);
    }
    else if (n <= 4){
        ofSetColor(ofColor::red);
    }
    else{
        ofSetColor(ofColor::green);
    }
    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    draw(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    draw(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    draw(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    draw(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    draw(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    draw(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
}