#include "BarnsleyFern.hpp"

BarnsleyFern::BarnsleyFern() {
    name = "BarnsleyFern";
    num = 0;
    level = 0;
}

BarnsleyFern::BarnsleyFern(string name, int level) : AbstractFractal(name, level) {
    this->name = name;
    this->level = level;
}

void BarnsleyFern::draw() {
    setNum((getLevel() + 10) * 1000);
    if (getNum() < 0){
        setNum(0);
        setLevel(-10);
    }
    else if (getNum() > 18000){
        setNum(18000);
        setLevel(8);
    }
    draw(0, 0, getNum());
}

void BarnsleyFern::draw(float x, float y, float n) {
    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    ofSetColor(ofColor::green);
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        draw(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        draw(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        draw(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        draw(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}