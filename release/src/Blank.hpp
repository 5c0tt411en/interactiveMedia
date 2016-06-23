#pragma once

#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "osc.hpp"

class BlankScene :public Scene {
public:
    BlankScene();
    ~BlankScene();
    void update();
    void draw();
};