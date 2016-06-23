#pragma once
#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "osc.hpp"

class OrgelScene: public Scene{
public:
    OrgelScene();
    ~OrgelScene();
    void update();
    void draw();
    vector<ofVec2f> poss;
    vector <float> line;
    
    ofSoundPlayer sound1;
    ofSoundPlayer sound2;
    ofSoundPlayer sound3;
    ofSoundPlayer sound4;
//    ofSoundPlayer sound5;
//    ofSoundPlayer sound6;
//    ofSoundPlayer sound7;
//    ofSoundPlayer sound8;
//    ofSoundPlayer sound9;
    
    ofSoundStream s_sonar;
//    const int t_posx1 = 100;
//    const int t_posx2 = 300;
//    const int t_posx3 = 500;
//    const int t_posx4 = 700;
//    const int t_posx5 = 900;
//    const int t_posx6 = 1100;
//    const int t_posx7 = 1400;
//    const int t_posx8 = 1500;
//    const int t_posx9 = 1700;
    
    const float t_posx1 = 100/1000;
    const float t_posx2 = 300/1000;
    const float t_posx3 = 500/1000;
    const float t_posx4 = 700/1000;

};
