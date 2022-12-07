#include "ofApp.hpp"
#include "SnowFlake.hpp"
#include "Circle.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;

    snowFlakeFractal = new SnowFlake();
    circleFractal = new Circle();
    treeFractal = new Tree();
    sierpinskiTriangleFractal = new SierpinskiTriangle();
    barnsleyFernFractal = new BarnsleyFern();
    newFractal = new NewFractal();

    fractalList.insert(fractalList.end(), {circleFractal, treeFractal, sierpinskiTriangleFractal, barnsleyFernFractal, snowFlakeFractal, newFractal});

    font.load("Sketch 3D.otf", 40);
    animation = false;
    keyLock = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    if (animation == true){                                                     //Animation 
        timer += 1;
        if (timer % 80 == 0){
            if (currentFractal->getIsMax() == true){
                direction = "Backward";
            }
            else if(currentFractal->getIsMin() == true){
                direction = "Forward";
            }
            
            if (direction == "Forward"){
                currentFractal->setLevel(currentFractal->getLevel() + 1);
            }
            else if (direction == "Backward"){
                currentFractal->setLevel(currentFractal->getLevel() - 1);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        currentFractal = fractalList.at(1);
        currentFractal->draw();
    } break;
    case '2': {
        // Tree
        currentFractal = fractalList.at(2);
        currentFractal->draw();
    } break;
    case '3': {
        // Sierpinski Triangle
        currentFractal = fractalList.at(3);
        currentFractal->draw();
    } break;
    case '4': {
        // Barnsley Fern
        currentFractal = fractalList.at(4);
        currentFractal->draw();
    } break;
    case '5': {
        // Koch SnowFlake
        currentFractal = fractalList.at(5);
        currentFractal->draw();
    } break;
    case '6':
        // New Fractal
        currentFractal = fractalList.at(6);
        currentFractal->draw();
    }

    ofSetColor(ofColor::white);

    font.drawString("Current Fractal: " + currentFractal->getName(), 10, 50);              // Shows Fractal Name
    font.drawString("Depth Level: " + ofToString(currentFractal->getLevel()), 10, 110);    // Shows Fractal Level
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_F11){
        ofSetFullscreen(fullscreen++ % 2 == 0);
    }
    else if (key == OF_KEY_ESC){
        ofSetFullscreen(false);
    }

    if (key == ' '){                                                        //keyLock for animation
        if (keyLock == false){
            currentFractal->setLevel(1);
            direction = "Forward";
            animation = true;
            keyLock = true;
        }
        else{
            animation = false;
            keyLock = false;
        }
    }

    if (keyLock != true){                                                   //keyLock that will open when not in the animation state
        if (key >= '1' && key <= '6'){
            mode = key;
        }
        if (key == OF_KEY_LEFT){
            currentFractal->setLevel(currentFractal->getLevel() - 1);
        }
        else if(key == OF_KEY_RIGHT){
            currentFractal->setLevel(currentFractal->getLevel() + 1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}