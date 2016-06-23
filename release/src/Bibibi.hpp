#pragma once

#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "osc.hpp"
#include "ofxOsc.h"

#define noiseNum 5

class BibibiScene: public Scene{
public:
    BibibiScene();
    ~BibibiScene();
    void setup();
    void draw();
    void update();
    vector<ofVec2f> position;
    const float distanceMin = 0.8;
    const float distanceMode2 = 0.4;
    const float distanceMode3 = 0.3;
    const float distanceMode4 = 0.2;
    const int circleAlpha = 255;
    float distance;
    float disX;
    float disY;
    float eachDisX;
    float eachDisY;
    float ranX[noiseNum];
    float ranY[noiseNum];
    int overlap;
    float noiseRatio;
    float clrMain;
    const int clrSub = 100;
    
//    ofSoundPlayer sound_01;
//    ofSoundPlayer sound_02;
//    ofSoundPlayer sound_03;
//    ofSoundPlayer sound_04;
    
    ofxOscSender sender;
    ofxOscMessage m1, m2, m3, m4;
};