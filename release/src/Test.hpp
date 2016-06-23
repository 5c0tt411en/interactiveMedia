#pragma once

#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "osc.hpp"

class TestScene :public Scene {
public:
    TestScene();
    ~TestScene();
    void update();
    void draw();
    vector<ofVec2f> poss;
};