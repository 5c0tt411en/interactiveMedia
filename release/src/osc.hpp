#pragma once

#include <vector>
#include <string>
#include "ofMain.h"
#include "ofxOsc.h"
#include "config.hpp"

namespace osc {
    extern ofxOscReceiver receiver;
    extern vector<ofVec2f> buffer;
    void init();
    void update();
    vector<ofVec2f> getpos_dummy();
    vector<ofVec2f> main_getpos();
    vector<ofVec2f> getpos(bool isDummy);
}