#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    kuroda_ = new kuroda();
    kuroda_->setup();
    suzuki_ = new suzuki();
    suzuki_->setup();
    ito_ = new ito();
    ito_->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef() - timeStamp;
    if (time >= 0 && time <time01) mode = 1;
    if (time >= time01 && time < time02) mode = 2;
    if (time >= time02 && time < time03) mode = 3;
    if (time > time03) timeStamp = ofGetElapsedTimef();
    
    switch (mode) {
        case 1:
            suzuki_->update();
            break;
        case 2:
            kuroda_->update();
            break;
        case 3:
            ito_->update();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (mode) {
        case 1:
            suzuki_->draw();
            break;
        case 2:
            kuroda_->draw();
            break;
        case 3:
            ito_->draw();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') ofToggleFullscreen();
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
