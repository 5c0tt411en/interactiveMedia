#pragma once

#include "ofMain.h"
#include "config.hpp"

#include "osc.hpp"

#include "Scene.hpp"
#include "Blank.hpp"
#include "Test.hpp"
#include "Bibibi.hpp"
#include "Moire.hpp"
#include "Orgel.hpp"
#include "Scratch.hpp"
#include "Tile.hpp"

using namespace std;
class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    Scene *scene;
    ofxOscReceiver osc_scene;
    
    int flash;
    ofColor flash_color;
};
