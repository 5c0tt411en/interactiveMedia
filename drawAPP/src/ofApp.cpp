#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //OSC
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(receiver.hasWaitingMessages()){
        ofxOscMessage msg;
        receiver.getNextMessage(&msg);
        int num = msg.getArgAsInt32(0);
        for(int i = 0; i < num; i++) {
            ofVec2f pos(msg.getArgAsFloat(2 * i + 1),msg.getArgAsFloat(2 * i + 2));
            pos.x = ofMap(pos.x, 0, 1, 0, ofGetWidth());
            pos.y = ofMap(pos.y, 0, 1, 0, ofGetHeight());
            buffer.push_back(pos);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < buffer.size(); i++) {
        ofDrawCircle(buffer[i].x, buffer[i].y, 10);
    }
    buffer.clear();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
