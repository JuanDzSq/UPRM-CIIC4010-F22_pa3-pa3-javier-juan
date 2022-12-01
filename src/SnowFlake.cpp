#include "SnowFlake.hpp"

SnowFlake::SnowFlake() {
    name = "Snow Flake";
}

SnowFlake::SnowFlake(string name, int level, int num, glm::vec2 start, glm::vec2 end) : AbstractFractal(name, 0, 0) {
    this->name = name;
    this->start = start;
    this->end = end;
}

void SnowFlake::draw() {
    float size = 0.74 * ofGetHeight();

    glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};

    setNum(getLevel() + 5);
    if (getNum() < 0){
        setNum(0);
        setLevel(getLevel() + 1);
    }
    else if (getNum() > 10){
        setNum(10);
        setLevel(getLevel() - 1);
    }
    if(getNum() > 0){
        draw(getNum(), new SnowFlake(name, level, num, p1, p2));
        draw(getNum(), new SnowFlake(name, level, num, p2, p3));
        draw(getNum(), new SnowFlake(name, level, num, p3, p1));
    }
}
void SnowFlake::draw(int n, SnowFlake *flake) {
    if (n < 2)
        ofDrawLine(flake->getStart(), flake->getEnd());
    else {
        draw(n - 1, new SnowFlake(name, level, num, flake->getA(), flake->getB()));
        draw(n - 1, new SnowFlake(name, level, num, flake->getB(), flake->getC()));
        draw(n - 1, new SnowFlake(name, level, num, flake->getC(), flake->getD()));
        draw(n - 1, new SnowFlake(name, level, num, flake->getD(), flake->getE()));
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