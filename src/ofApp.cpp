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

    font.load("Sketch 3D.otf", 30);
    animation = false;
    speed = 2;
    speedOptions = {160, 120, 80, 50, 30};
}

//--------------------------------------------------------------
void ofApp::update() {
    if (animation == true){                                                     //Animation 
        timer += 1;
        if (timer % speedOptions.at(speed) == 0){                               // The speed and speedOptions controll the speed of the animation
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

    if(animation == true){
        font.drawString("Animation Speed: " + to_string(speed - 2), 10, 170);               // Shows animation speed
        ofDrawBitmapString("Press the arrow keys to \nchange animation speed", 10, 190);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_F11){
        ofSetFullscreen(fullscreen++ % 2 == 0);
    }
    else if (key == OF_KEY_ESC){
        ofSetFullscreen(false);
    }

    if (key == ' '){                                                        // Pressing Space will switch between animation and no animation
        if (animation == false){
            currentFractal->setLevel(1);
            direction = "Forward";
            animation = true;
        }
        else{
            animation = false;
            speed = 2;
        }
    }

    if (animation == false){                                                   // While in animation, switching modes and levels is disabled
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
    else {   
        // Animation speed change using arrow keys while in an animation state      
        if (key == OF_KEY_LEFT){
            if (speed > 0){
                speed--;
            }
        }
        else if(key == OF_KEY_RIGHT){
            if(speed < speedOptions.size() - 1){
                speed++;
            }
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