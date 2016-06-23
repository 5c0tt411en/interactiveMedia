#include "Orgel.hpp"

OrgelScene::OrgelScene(){
    int bufferSize = 256;
    line.assign(bufferSize, 0.0);
    sound1.loadSound("./Orgel/LC.mp3");
    sound2.loadSound("./Orgel/ME.mp3");
    sound3.loadSound("./Orgel/MG.mp3");
    sound4.loadSound("./Orgel/HC.mp3");
//    sound5.loadSound("./Orgel/ME.mp3");
//    sound6.loadSound("./Orgel/MG.mp3");
//    sound7.loadSound("./Orgel/HC.mp3");
//    sound8.loadSound("./Orgel/HE.mp3");
//    sound9.loadSound("./Orgel/HG.mp3");
}
OrgelScene::~OrgelScene(){

}
void OrgelScene::update(){
    poss = osc::getpos(config::USE_DUMMY_DATA);
}
void OrgelScene::draw(){
    ofPushStyle();
//    ofLine(t_posx1, 0, t_posx1, ofGetWidth());
//    ofLine(t_posx2, 0, t_posx2, ofGetWidth());
//    ofLine(t_posx3, 0, t_posx3, ofGetWidth());
//    ofLine(t_posx4, 0, t_posx4, ofGetWidth());
    
    ofSetLineWidth(2);
    ofLine(t_posx1, 0, t_posx1, 1);
    ofLine(t_posx2, 0, t_posx2, 1);
    ofLine(t_posx3, 0, t_posx3, 1);
    ofLine(t_posx4, 0, t_posx4, 1);
    
    if(poss.size() == 0)
        return;
    for(auto it = poss.begin(); it != poss.end(); it++){
        ofCircle(*it, 0.02);
        ofPushMatrix();
        ofScale(1./config::HEIGHT, 1./config::HEIGHT);
        
        for (int i = 0; i < line.size(); i++){
            ofVertex(t_posx1-line[i]*180.0f,i*2);
        }
        
        ofSetColor(255, 255, 255);
        ofSetLineWidth(1);
        
//        ofLine(t_posx1, 0, t_posx1, ofGetWidth());
//        ofLine(t_posx2, 0, t_posx2, ofGetWidth());
//        ofLine(t_posx3, 0, t_posx3, ofGetWidth());
//        ofLine(t_posx4, 0, t_posx4, ofGetWidth());
//        ofLine(t_posx5, 0, t_posx5, ofGetWidth());
//        ofLine(t_posx6, 0, t_posx6, ofGetWidth());
//        ofLine(t_posx7, 0, t_posx7, ofGetWidth());
//        ofLine(t_posx8, 0, t_posx8, ofGetWidth());
//        ofLine(t_posx9, 0, t_posx9, ofGetWidth());
        
        if (t_posx1-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx1+6) {
            ofSetColor(245, 58, 135);
            ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < line.size(); i++){
                ofVertex(t_posx1-line[i]*180.0f,i*line.size()/1);
            }
            ofEndShape(false);
            for (int i = 1; i<10; i++) {
                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
            }
            sound1.play();
            ofSetLineWidth(1);
        }
        
        
        
        if (t_posx2-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx2+6) {
            ofSetColor(245, 58, 135);
            ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < line.size(); i++){
                ofVertex(t_posx2-line[i]*180.0f,i*line.size()/1);
            }
            ofEndShape(false);
            for (int i = 1; i<10; i++) {
                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
            }
            sound2.play();
            ofSetLineWidth(1);
        }
        
        
        
        if (t_posx3-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx3+6) {
            ofSetColor(245, 58, 135);
            ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < line.size(); i++){
                ofVertex(t_posx3-line[i]*180.0f,i*line.size()/1);
            }
            ofEndShape(false);
            for (int i = 1; i<10; i++) {
                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
            }
            sound3.play();
            ofSetLineWidth(1);
        }
        
        
        
        if (t_posx4-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx4+6) {
            ofSetColor(245, 58, 135);
            ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < line.size(); i++){
                ofVertex(t_posx4-line[i]*180.0f,i*line.size()/1);
            }
            ofEndShape(false);
            for (int i = 1; i<10; i++) {
                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
            }
            sound4.play();
            ofSetLineWidth(1);
        }
        
//        if (t_posx5-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx5+6) {
//            ofSetColor(245, 58, 135);
//            ofSetLineWidth(3);
//            ofBeginShape();
//            for (unsigned int i = 0; i < line.size(); i++){
//                ofVertex(t_posx5-line[i]*180.0f,i*line.size()/1);
//            }
//            ofEndShape(false);
//            for (int i = 1; i<10; i++) {
//                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
//            }
//            sound8.play();
//            ofSetLineWidth(1);
//        }
//        
//        if (t_posx6-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx6+6) {
//            ofSetColor(245, 58, 135);
//            ofSetLineWidth(3);
//            ofBeginShape();
//            for (unsigned int i = 0; i < line.size(); i++){
//                ofVertex(t_posx6-line[i]*180.0f,i*line.size()/1);
//            }
//            ofEndShape(false);
//            for (int i = 1; i<10; i++) {
//                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
//            }
//            sound2.play();
//            ofSetLineWidth(1);
//        }
//        
//        if (t_posx7-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx7+6) {
//            ofSetColor(245, 58, 135);
//            ofSetLineWidth(3);
//            ofBeginShape();
//            for (unsigned int i = 0; i < line.size(); i++){
//                ofVertex(t_posx7-line[i]*180.0f,i*line.size()/1);
//            }
//            ofEndShape(false);
//            for (int i = 1; i<10; i++) {
//                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
//            }
//            sound4.play();
//            ofSetLineWidth(1);
//        }
//        
//        if (t_posx8-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx8+6) {
//            ofSetColor(245, 58, 135);
//            ofSetLineWidth(3);
//            ofBeginShape();
//            for (unsigned int i = 0; i < line.size(); i++){
//                ofVertex(t_posx8-line[i]*180.0f,i*line.size()/1);
//            }
//            ofEndShape(false);
//            for (int i = 1; i<10; i++) {
//                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
//            }
//            sound6.play();
//            ofSetLineWidth(1);
//        }
//        
//        if (t_posx9-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx9+6) {
//            ofSetColor(245, 58, 135);
//            ofSetLineWidth(3);
//            ofBeginShape();
//            for (unsigned int i = 0; i < line.size(); i++){
//                ofVertex(t_posx9-line[i]*180.0f,i*line.size()/1);
//            }
//            ofEndShape(false);
//            for (int i = 1; i<10; i++) {
//                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
//            }
//            sound5.play();
//            ofSetLineWidth(1);
//        }
        
        if (t_posx4-6 <= it->x*config::HEIGHT && it->x*config::HEIGHT <= t_posx4+6) {
            ofSetColor(245, 58, 135);
            ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < line.size(); i++){
                ofVertex(t_posx4-line[i]*180.0f,i*line.size()/1);
            }
            ofEndShape(false);
            for (int i = 1; i<10; i++) {
                ofCircle(config::HEIGHT * it->x,config::HEIGHT * it->y, 5*i);
            }
            sound4.play();
            ofSetLineWidth(1);
        }
        ofPopMatrix();
    }
    ofPopStyle();
    
}