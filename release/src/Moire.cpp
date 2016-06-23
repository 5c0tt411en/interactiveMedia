#include "Moire.hpp"

const float Moire::MAX_SEC = 3;
const float Moire::MAX_RAD = 0.8;
const int MoireScene::MAX_MOIRE_NUM = 20;
Moire::Moire(float x, float y){
    pos.x = x;
    pos.y = y;
    
    stime = ofGetElapsedTimef();
    for (int i = 0; i < MOIRE_NUM; i++){
        this->x[i] = sin(i);
        this->y[i] = cos(i);
    }
    ofxOscSender sender;
    sender.setup("127.0.0.1", 57120);
    ofxOscMessage msg;
    msg.setAddress("/moire");
    sender.sendMessage(msg);
}

Moire::~Moire(){}

bool Moire::islive(){
    return ofGetElapsedTimef() - stime < MAX_SEC;
}

void Moire::draw(){
    float r = MAX_RAD * (ofGetElapsedTimef() - stime) / MAX_SEC;
    if (r < 0)
        return;
    ofPushStyle();
    float a = pos.x;
    float b = pos.y;
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255, 255, 255, 200 * (MAX_RAD - r) / MAX_RAD);
    for (int i =0; i < MOIRE_NUM - 1; i++ ){
        ofLine(a + x[i] * r, b + y[i] * r, a + x[i+1] * r, b + y[i+1] * r);
    }
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    ofPopStyle();
}


MoireScene::MoireScene(){
}
MoireScene::~MoireScene(){}

void MoireScene::update(){
    for(auto it = ms.begin(); it != ms.end();){
        if(!(*it)->islive()) {
            delete  *it;
            it = ms.erase(it);
        }else {
            ++it;
        }
    }
    poss = osc::getpos(config::USE_DUMMY_DATA);
    static float _stime = 0;
    for(auto it = poss.begin(); it != poss.end(); it++){
        if( ofGetElapsedTimef() - _stime > 0.2 && ms.size() < MAX_MOIRE_NUM){
            if(ofRandom(1) < 0.2){
                Moire *m = new Moire(it->x, it->y);
                _stime = ofGetElapsedTimef();
                ms.push_back(m);
                if(ofRandom(1.) < 0.3){
                    Moire *_m = new Moire(it->x, it->y);
                    _m->stime = ofGetElapsedTimef() + 0.4;
                    ms.push_back(_m);
                }
            }
        }
    }
}
void MoireScene::draw(){
    ofPushStyle();
    for(auto it = ms.begin(); it != ms.end(); it++){
        (*it)->draw();
    }
    if(config::DEBUG){
        for(auto it = poss.begin(); it != poss.end(); it++){
            ofCircle(*it, 0.02);
        }
    }
    ofPopStyle();
}
