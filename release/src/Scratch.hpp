#pragma once
#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "osc.hpp"

class ScratchScene :public Scene{
public:
    ScratchScene();
    ~ScratchScene();
    void update();
    void draw();
    void setup();
    
    int counter;
    
    vector<ofVec2f> poss;
    ofImage myImage1;
    ofImage myImage2;
    
    ofVec2f part[75][30];
};