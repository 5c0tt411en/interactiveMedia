#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(config::FPS);
    ofBackground(ofColor::black);
    scene = new TestScene();
    osc::init();
    osc_scene.setup(config::OSC_SCN_RECV_PORT);
    if(config::DEBUG){
        using namespace config;
        const int debug_window_height = HEIGHT * HEIGHT / DIVIDED_WIDTH / 4;
        ofSetWindowShape(HEIGHT, DIVIDED_WIDTH + debug_window_height);
    }else{
        ofSetWindowShape(config::HEIGHT, config::DIVIDED_WIDTH);
    }
}

void ofApp::update(){
    flash = -1;
    // scene change
    if(osc_scene.hasWaitingMessages()){
        ofxOscMessage msg;
        osc_scene.getNextMessage(&msg);
        string addr = msg.getAddress();
        if(addr == "/scene/test"){
            delete scene;
            scene = new TestScene();
        } else if (addr == "/scene/bibibi"){
            delete scene;
            scene = new BibibiScene();
        } else if (addr == "/scene/moire"){
            delete scene;
            scene = new MoireScene();
        } else if (addr == "/scene/orgel"){
            delete scene;
            scene = new OrgelScene();
        } else if (addr == "/scene/scratch"){
            delete scene;
            scene = new ScratchScene();
        } else if (addr == "/scene/tile"){
            delete  scene;
            scene = new TileScene();
        } else if (addr == "/scene/blank"){
            delete  scene;
            scene = new BlankScene();
        } else if (addr == "/flash") {
            flash = msg.getArgAsInt32(0);
            flash_color.set(msg.getArgAsFloat(1), msg.getArgAsFloat(2), msg.getArgAsFloat(3));
        }
    }
    
    // for get postion
    osc::update();
    scene->update();
}

void ofApp::draw(){
    
    ofPushMatrix();
    
    // main window
    ofPushMatrix();
    ofRotateZ(90);
    ofTranslate(-config::WINDOW_ID * config::DIVIDED_WIDTH, -config::HEIGHT);
    float scale = config::HEIGHT;
    ofScale( scale, scale);
    scene->draw();
    ofPopMatrix();
    
    // under window
    if(config::DEBUG){
        {
            ofPushMatrix();
            ofTranslate(0, config::DIVIDED_WIDTH);
            {
                ofPushStyle();
                ofSetColor(ofColor::black);
                ofRect(0, 0, config::HEIGHT, config::DIVIDED_WIDTH);
                ofSetColor(*(new ofColor(255, 255, 255, 60)));
                ofRect(0, 0, config::HEIGHT, config::DIVIDED_WIDTH);
                ofPopStyle();
            }
            {
                ofPushMatrix();
                float scale = config::HEIGHT * config::HEIGHT / config::WIDTH ;
                ofScale( scale, scale);
                scene->draw();
                for(float i = 0; i < 4; i++){
                    ofSetLineWidth(0.02);
                    ofLine(i * config::ASPECT_RATIO / 4, 0,
                           i * config::ASPECT_RATIO / 4, 1);
                    if( i == config::WINDOW_ID ){
                        ofPushStyle();
                        ofSetColor(*(new ofColor(255, 255, 255, 60)));
                        ofRect( i * config::ASPECT_RATIO / 4, 0,
                               config::ASPECT_RATIO / 4, 1);
                        ofPopStyle();
                    }
                }
                ofPopMatrix();
            }
            ofPopMatrix();
        }
    }
    ofPopMatrix();

}

// for only debug
void ofApp::keyPressed(int key){
    if (key == '0' ){
        delete scene;
        scene = new TestScene();
    } else if (key == '1' ){
        delete scene;
        scene = new BibibiScene();
    } else if (key == '2' ){
        delete scene;
        scene = new MoireScene();
    } else if (key == '3' ){
        delete scene;
        scene = new OrgelScene();
    } else if (key == '4' ){
        delete scene;
        scene = new ScratchScene();
    } else if (key == '5' ){
        delete scene;
        scene = new TileScene();
    } else if (key == '9' ){
        delete scene;
        scene = new BlankScene();
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){ }
