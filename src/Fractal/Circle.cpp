#include "Circle.hpp"

Circle::Circle() {
    name = "Circle";
    num = 0;
    level = 0;

    r = 0.31 * ofGetHeight();
}

Circle::Circle(string name, int level, float r, float angle) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
    this->r = r;
    this->angle = angle;
}

void Circle::draw(){
    angle += 0.01;
    setNum(3 + getLevel());
    if (getNum() < 0){
        setNum(0);
        setLevel(-3);
    }
    else if (getNum() > 6){
        setNum(6);
        setLevel(3);
    }
    draw(ofGetWidth() / 2, ofGetHeight() / 2, r, getNum());
}

void Circle::draw(float x, float y, float r, int n) {
    if (n == 0) return;

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