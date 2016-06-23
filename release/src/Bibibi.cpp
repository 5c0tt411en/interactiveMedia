#include "Bibibi.hpp"

BibibiScene::BibibiScene(){
    sender.setup("127.0.0.1", 57120);
    
    m1.setAddress("/m1");
    m2.setAddress("/m2");
    m3.setAddress("/m3");
    m4.setAddress("/m4");
    //    ofEnableSmoothing();
    //
    //    sound_01.loadSound("./Bibibi/mode1.mp3");
    //    sound_02.loadSound("./Bibibi/mode2.mp3");
    //    sound_03.loadSound("./Bibibi/mode3.mp3");
    //    sound_04.loadSound("./Bibibi/mode4.mp3");
}
BibibiScene::~BibibiScene(){
    ofFill();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

void BibibiScene::update(){
    position = osc::getpos(config::USE_DUMMY_DATA);
}

void BibibiScene::draw(){
    const float kakuritsu = 4. / config::FPS;
    ofPushStyle();
    ofNoFill();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(64);
    if(position.size() == 0)
        return;
    for(auto i = position.begin(); i != position.end(); i++){
        ofCircle(*i, 0.005);//just for point.
        overlap = 0;
        for (auto j = position.begin(); j != position.end(); j++) {
            if (i < j) {
                disX = j->x - i->x;
                disY = j->y - i->y;
                distance = sqrt(disX * disX + disY * disY);
                noiseRatio = 1 / distance;
                eachDisX = disX / noiseNum;
                eachDisY = disY / noiseNum;
                clrMain = 255 * ofRandom(0.3, 1.0);
                if (distance < distanceMin) {
                    ofSetColor(clrSub, clrSub, clrMain, circleAlpha);
                    if( ofRandom(1.) < kakuritsu)
                    sender.sendMessage(m1);
                }
                if (distance < distanceMode2) {
                    ofSetColor(clrSub, clrMain, clrSub, circleAlpha);
                    if( ofRandom(1.) < kakuritsu)
                        sender.sendMessage(m2);
                }
                if (distance < distanceMode3) {
                    ofSetColor(clrMain, clrMain, clrSub, circleAlpha);
                    if( ofRandom(1.) < kakuritsu)
                        sender.sendMessage(m3);
                }
                if (distance < distanceMode4) {
                    ofSetColor(clrMain, clrSub, clrSub, circleAlpha);
                    if( ofRandom(1.) < kakuritsu)
                        sender.sendMessage(m4);
                }
                if (distance < distanceMin) {
                    if (overlap == 0) {
                        ofCircle(*i, ofRandom(0.003 * noiseRatio, 0.02 * noiseRatio * 0.7));
                        ofCircle(*j, ofRandom(0.003 * noiseRatio, 0.02 * noiseRatio * 0.7));
                        overlap++;
                    }
                    for (int k = 0; k < noiseNum; k++) {
                        ranX[k] = ofRandom(-0.01 * noiseRatio, 0.01 * noiseRatio);
                        ranY[k] = ofRandom(-0.01 * noiseRatio, 0.01 * noiseRatio);
                    }
                    for (int k = 0; k < noiseNum; k++) {
                        ofSetLineWidth(noiseRatio);
                        if (k != 0 && k != noiseNum - 1) {
                            ofLine(i->x + k * eachDisX + ranX[k],
                                   i->y + k * eachDisY + ranY[k],
                                   i->x + (k + 1) * eachDisX + ranX[k + 1],
                                   i->y + (k + 1) * eachDisY + ranY[k + 1]);
                        }
                        else if (k == 0) {
                            ofLine(i->x,
                                   i->y,
                                   i->x + (k + 1) * eachDisX + ranX[k + 1],
                                   i->y + (k + 1) * eachDisY + ranY[k + 1]);
                        }
                        else {
                            ofLine(i->x + k * eachDisX + ranX[k],
                                   i->y + k * eachDisY + ranY[k],
                                   i->x + (k + 1) * eachDisX,
                                   i->y + (k + 1) * eachDisY);
                        }
                    }
                }
            }
        }
    }
    ofSetColor(255);
    ofFill();
    ofPopStyle();
}