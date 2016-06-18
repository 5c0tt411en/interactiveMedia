#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(30);
    ofShowCursor();
    gui.setup();
    gui.add(cam_id.setup("select kinect", false));
    gui.add(upside_down.setup("upside down", false));
    gui.add(grid.setup("grid", false));
    gui.add(test.setup("test", false));
    gui.add(window_id.setup("window id",   0,     0,  3));
    gui.add(near.setup("near",             255,   40,  255));
    gui.add(far.setup("far",               100,    40,  255));
    gui.add(min_radius.setup("min_radius", 1800 , 200,12000));
    gui.add(max_radius.setup("max_radius", 12000, 200,12000));
    gui.add(angle.setup("kinect angle",    0,     -30,  30));
    gui.add(thresh.setup("contour thresh", 255,   0,  255));
    gui.add(split.setup("split",           65,    30,  100));
    
    gui.setPosition((MARGIN - 1 + 0.825) * k.width / 2 , (MARGIN - 1) * k.height / 4);
    
    k.listDevices();
    k.init();
    k.open(k.nextAvailableId());
    
    kimage.allocate(k.width, k.height, OF_IMAGE_COLOR);
    dimage.allocate(k.width, k.height, OF_IMAGE_GRAYSCALE);
    fimage.allocate(k.width, k.height, OF_IMAGE_GRAYSCALE);
    
    ofSetWindowShape(MARGIN * 2.2 * k.width / 2, MARGIN * k.height / 2);
    cout << "kinect.width, kinect.height: " << k.width << "," << k.height << endl;
    float offsetx = (MARGIN - 1) * k.width / 4;
    float offsety = (MARGIN - 1) * k.height / 4;
    left_top.set(offsetx, offsety);
    right_bottom.set(offsetx + (k.width / 2), offsety + (k.height / 2));
}

void ofApp::update(){

    if(test){
        ofxOscMessage _msg;
        _msg.setAddress("/pos");
        int num = 3;
        _msg.addIntArg((num + 1) * (num + 1));
        for(int i = 0; i <= num; i++) {
            for(int j = 0; j <= num; j++){
                float width = 2 * (right_bottom.x - left_top.x);
                float height = 2 * (right_bottom.y - left_top.y);
                float kratio = float(k.width) / k.height;
                float ratio = width / height;
                float offsetx = 2 * (left_top.x - ((MARGIN - 1) * k.width / 4));
                float offsety = 2 * (left_top.y - ((MARGIN - 1) * k.height / 4));
                float x = (i * k.width / num) - offsetx;
                float y = (j * k.height / num) - offsety;
                float sendx = (y / height) / ratio + (window_id / ratio);
                float sendy = (k.width - x) / k.width;
                if ( sendx < window_id / ratio || sendx > ( window_id + 1 ) / ratio )
                    continue;
                _msg.addFloatArg(sendx);
                _msg.addFloatArg(sendy);
            }
        }
        ofxOscSender _sender;
        _sender.setup(SELF, OSC_SEND_PORT);
        _sender.sendMessage(_msg);
    }
    
    
    if(!k.isConnected())
        return;
    
    if( int(cam_id) != k.getDeviceId() ){
        k.close();
        k.open(int(cam_id));
    }
    k.setCameraTiltAngle(angle);
    k.update();
    if(k.isFrameNew()){
        kimage.setFromPixels(k.getPixels(), k.width, k.height, OF_IMAGE_COLOR);
        dimage.setFromPixels(k.getDepthPixels(), k.width, k.height, OF_IMAGE_GRAYSCALE);
        if(upside_down){
            kimage.rotate90(2);
            dimage.rotate90(2);
        }
        unsigned char * pix = dimage.getPixels();
        int numPixels = dimage.getWidth() * dimage.getHeight();
        for(int i = 0; i < numPixels; i++)
            pix[i] = (pix[i] < near && pix[i] > far)? 255: 0;
        if(grid)
            for(int i = 0; i < numPixels; i++)
                if((i / k.width % split == 0) || (i % k.width % split == 0) )
                    pix[i] = 0;
        fimage.setFromPixels(pix, k.width,k.height, OF_IMAGE_GRAYSCALE);
        ofxCvGrayscaleImage gray;
        gray.allocate(k.width, k.height);
        gray.setFromPixels(fimage.getPixels(), k.width, k.height);
        cntr.findContours(gray, min_radius, max_radius, 18, true, true);
    }

    ofxOscMessage msg;
    msg.setAddress("/pos");
    msg.addIntArg(cntr.nBlobs );
    float width = 2 * (right_bottom.x - left_top.x);
    float height = 2 * (right_bottom.y - left_top.y);
    float ratio = width / height;
    float offsetx = 2 * (left_top.x - ((MARGIN - 1) * k.width / 4));
    float offsety = 2 * (left_top.y - ((MARGIN - 1) * k.height / 4));
    for(int i = 0; i < cntr.nBlobs; i++) {
        ofxCvBlob blob =  cntr.blobs.at(i);
        ofPoint pos = blob.boundingRect.getCenter();
        float x = pos.x - offsetx;
        float y = pos.y - offsety;
        float sendx = (y / height) / ratio + (window_id / ratio);
        float sendy = (k.width - x) / k.width;
//        if ( sendx < window_id / ratio || sendx > ( window_id + 1 ) / ratio )
//            continue;
        msg.addFloatArg(sendx);
        msg.addFloatArg(sendy);
    }
    ofxOscSender self;
    self.setup(SELF, OSC_SEND_PORT);
    self.sendMessage(msg); 
}

void ofApp::draw(){
    ofPushMatrix();
    {
        ofScale(.5, .5);
        ofPushMatrix();
        ofTranslate(0, (MARGIN - 1) * k.height / 2);
        ofTranslate((MARGIN - 1) * k.width / 2, 0);
//        kimage.draw(0,           0,     k.width, k.height);
//        ofTranslate( 2 * (MARGIN - 1) * k.width / 2, 0);
        dimage.draw(0,       0,     k.width, k.height);
        ofTranslate( 3 * (MARGIN - 1) * k.width / 2, 0);
        fimage.draw(k.width, 0,     k.width, k.height);
        cntr.draw(k.width, 0, k.width, k.height);
        ofPushStyle();
        ofPushMatrix();
        {
            ofSetColor(255, 0, 0, 100);
            ofTranslate(2 * k.width, 0);
            for(int i = 0 ; i < cntr.nBlobs; i++){
                ofxCvBlob blob =  cntr.blobs.at(i);
                ofCircle(blob.boundingRect.getCenter(), 5);
            }
        }
        ofPopMatrix();
        ofPopStyle();
        ofPopMatrix();
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255, 255, 255, 100);
    ofRect(left_top, right_bottom.x - left_top.x, right_bottom.y - left_top.y);
    ofSetColor(255, 255, 0);
    ofCircle(left_top, 5);
    ofSetColor(255, 0, 255);
    ofCircle(right_bottom, 5);
    ofSetColor(0, 255, 255, 255);
    ofCircle((left_top + right_bottom ) / 2, 10);
    ofPopStyle();
    ofPopMatrix();
    
    gui.draw();
}

void ofApp::keyPressed(int key){
    if(key == 'l'){
        left_top.set(mouseX, mouseY);
    } else if(key == 'r'){
        right_bottom.set(mouseX, mouseY);
    } else if(key == 'c'){
        ofVec2f center = (left_top + right_bottom ) / 2;
        ofVec2f mouse(mouseX, mouseY);
        ofVec2f diff = mouse - center;
        left_top = left_top + diff;
        right_bottom = right_bottom + diff;
    }
}
void ofApp::keyReleased(int key){
}
void ofApp::mouseMoved(int x, int y ){
}
void ofApp::mouseDragged(int x, int y, int button) {
}
void ofApp::mousePressed(int x, int y, int button){
}
void ofApp::mouseReleased(int x, int y, int button){
}
void ofApp::windowResized(int w, int h){
}
void ofApp::gotMessage(ofMessage msg){
}
void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
