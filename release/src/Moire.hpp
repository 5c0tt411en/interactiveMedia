#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include "Scene.hpp"

#include "osc.hpp"


const int MOIRE_NUM = 100;
class Moire {
public:
    static const float MAX_SEC;
    static const float MAX_RAD;
    int refrain;
    float stime;
    ofVec2f pos;
    float x[MOIRE_NUM];
    float y[MOIRE_NUM];
    Moire(float x, float y);
    ~Moire();
    bool islive();
    void draw();
};

class MoireScene :public Scene {
public:
    static const int MAX_MOIRE_NUM;
    MoireScene();
    ~MoireScene();
    void update();
    void draw();
    
    vector<ofVec2f> poss;
    vector<Moire*> ms;

};
