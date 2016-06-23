#pragma once

#include <vector>
#include "ofMain.h"
#include "Scene.hpp"
#include "Moire.hpp"
#include "osc.hpp"


const int TILE_MOIRE_NUM = 100;

class Tile {
public:
    static const float SIZE;
    static const float DEATH_DISTANCE;
    static const float EXPLODE_RAD;
    static const float EXPLODE_SEC;
    static const int SPLIT_NUM;
    static const float MAX_LIFE_TIME;
    ofVec2f pos;
    float stime;
    float explode_time;
    float x[TILE_MOIRE_NUM];
    float y[TILE_MOIRE_NUM];
    Tile();
    ~Tile();
    void update(vector<ofVec2f> persons);
    void draw();
    bool islive();
    
};

class TileScene :public Scene {
public:
    const int TILE_NUM = 40;
    vector<Tile*> tiles;
    vector<ofVec2f> persons;
    TileScene();
    ~TileScene();
    void update();
    void draw();
};