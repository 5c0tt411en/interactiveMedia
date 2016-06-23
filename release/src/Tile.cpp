#include "Tile.hpp"

const float Tile::SIZE              = 0.05;
const float Tile::DEATH_DISTANCE    = 0.15;
const float Tile::EXPLODE_RAD       = 0.6;
const float Tile::EXPLODE_SEC       = 0.4;
const float Tile::MAX_LIFE_TIME     = 5;

Tile::Tile(){
    stime = ofGetElapsedTimef();
    explode_time = MAXFLOAT;
    pos.x = int(ofRandom(config::ASPECT_RATIO / 4) / SIZE) * SIZE;
    pos.y = int(ofRandom(1.) / SIZE) * SIZE;
}

Tile::~Tile(){}

void Tile::update(vector<ofVec2f> persons){
    if( explode_time == MAXFLOAT )
        for(auto it = persons.begin(); it != persons.end(); it++)
            if(it->distance(pos) < DEATH_DISTANCE){
                explode_time = ofGetElapsedTimef();
                for (int i = 0; i < MOIRE_NUM; i++){
                    this->x[i] = sin(i);
                    this->y[i] = cos(i);
                }
                ofxOscSender sender;
                sender.setup("127.0.0.1", 57120);
                ofxOscMessage msg;
                msg.setAddress("/tile");
                sender.sendMessage(msg);
            }
}

void Tile::draw(){
    if( explode_time == MAXFLOAT) {
        ofPushStyle();
        ofSetColor(255,255 * (MAX_LIFE_TIME - (ofGetElapsedTimef() - stime))/MAX_LIFE_TIME);
        ofCircle(pos, SIZE / 2);
        ofSetColor(ofColor::black);
        ofCircle(pos, SIZE / 3);
        ofPopStyle();
    } else {
        float r = Tile::EXPLODE_RAD * (ofGetElapsedTimef() - explode_time) / Tile::EXPLODE_SEC;
        if (r < 0)
            return;
        ofPushStyle();
        float a = pos.x;
        float b = pos.y;
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetColor(255, 255, 255, 255 * (Tile::EXPLODE_RAD - r) / Tile::EXPLODE_SEC);
        for (int i =0; i < MOIRE_NUM - 1; i++ ){
            ofLine(a + x[i] * r, b + y[i] * r, a + x[i+1] * r, b + y[i+1] * r);
        }
        ofEnableBlendMode(OF_BLENDMODE_DISABLED);
        ofPopStyle();
    }
}

bool Tile::islive(){
    if(explode_time == MAXFLOAT){
        return (ofGetElapsedTimef() - stime < MAX_LIFE_TIME);
    } else {
        return (ofGetElapsedTimef() - explode_time < EXPLODE_SEC);
    }
}

TileScene::TileScene(){}
TileScene::~TileScene(){}

void TileScene::update(){
    for(int i = 0; i < TILE_NUM - tiles.size(); i++ )
        tiles.push_back(new Tile());

    for(auto it = tiles.begin(); it != tiles.end();){
        if(!(*it)->islive()) {
            delete  *it;
            it = tiles.erase(it);
        }else {
            ++it;
        }
    }
    
    persons = osc::getpos(config::USE_DUMMY_DATA);
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        (*it)->update(persons);
    }
}

void TileScene::draw(){

    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        (*it)->draw();
    }
    

    if (config::DEBUG)
        for(auto it = persons.begin(); it != persons.end(); it++)
            ofCircle(*it, 0.01);

}

