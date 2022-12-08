#pragma once

#include <cmath>

#include "ofMain.h"
#include "SnowFlake.hpp"
#include "Circle.hpp"
#include "Tree.hpp"
#include "SierpinskiTriangle.hpp"
#include "BarnsleyFern.hpp"
#include "NewFractal.hpp"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    unsigned int fullscreen;

    //Animation 
    bool animation;
    string direction;
    unsigned int timer;
    unsigned int speed;
    vector<int> speedOptions;
    bool keyLock;

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector <Fractal*> fractalList = {NULL};    //Starts with NULL so that the indexes for the fractals are 1-6
    Fractal* currentFractal;

    // Fractals
    SnowFlake* snowFlakeFractal;
    Circle* circleFractal;
    Tree* treeFractal;
    SierpinskiTriangle* sierpinskiTriangleFractal;
    BarnsleyFern* barnsleyFernFractal;
    NewFractal* newFractal;

    ofTrueTypeFont font;
};
