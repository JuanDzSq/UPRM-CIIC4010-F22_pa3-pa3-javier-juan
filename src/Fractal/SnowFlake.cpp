#include "SnowFlake.hpp"

SnowFlake::SnowFlake() {
    name = "Snow Flake";
    num = 0;
    level = 5;

    size = 0.74 * ofGetHeight();
}

SnowFlake::SnowFlake(string name, int level, float size, glm::vec2 start, glm::vec2 end) : AbstractFractal(name, level) {
    this->size = size;
    this->start = start;
    this->end = end;
}

void SnowFlake::draw() {

    glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};

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
    if(getNum() > 0){
        draw(getNum(), new SnowFlake(name, level, size, p1, p2));
        draw(getNum(), new SnowFlake(name, level, size, p2, p3));
        draw(getNum(), new SnowFlake(name, level, size, p3, p1));
    }
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
void SnowFlake::draw(int n, SnowFlake *flake) {
    if (n < 2)
        ofDrawLine(flake->getStart(), flake->getEnd());
    else {
        draw(n - 1, new SnowFlake(name, level, size, flake->getA(), flake->getB()));
        draw(n - 1, new SnowFlake(name, level, size, flake->getB(), flake->getC()));
        draw(n - 1, new SnowFlake(name, level, size, flake->getC(), flake->getD()));
        draw(n - 1, new SnowFlake(name, level, size, flake->getD(), flake->getE()));
    }
    delete flake;
}

glm::vec2 SnowFlake::getA() { return start; }

glm::vec2 SnowFlake::getB() {
    double x = (end.x - start.x) / 3.0 + start.x;
    double y = (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getC() {
    glm::vec2 v1 = this->getB();
    glm::vec2 v2 = {(end.x - start.x) / 3.0, (end.y - start.y) / 3.0};

    auto rotate = [](glm::vec2 v, double angle) {
        return glm::vec2{v.x * cos(angle) - v.y * sin(angle), v.x * sin(angle) + v.y * cos(angle)};
    };
    v2 = rotate(v2, -PI / 3);
    return {v1.x + v2.x, v1.y + v2.y};
}

glm::vec2 SnowFlake::getD() {
    double x = 2.0 * (end.x - start.x) / 3.0 + start.x;
    double y = 2.0 * (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getE() { return end; }