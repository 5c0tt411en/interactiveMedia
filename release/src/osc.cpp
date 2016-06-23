#include "osc.hpp"
namespace osc {
    
    ofxOscReceiver receiver;
    vector<ofVec2f> buffer;
    
    void init(){
        receiver.setup(config::OSC_POS_RECV_PORT);
    }
    
    void update(){
        buffer.clear();
        while(receiver.hasWaitingMessages()){
            ofxOscMessage msg;
            receiver.getNextMessage(&msg);
            int num = msg.getArgAsInt32(0);
            for(int i = 0; i < num; i++) {
                ofVec2f pos(msg.getArgAsFloat(2 * i + 1),msg.getArgAsFloat(2 * i + 2));
                buffer.push_back(pos);
            }
        }
    }
    
    vector<ofVec2f> getpos_dummy(){
        static int count = 0;
        const int sec = 30;
        const int step = config::FPS * sec;
        const int max_people = 15;
        count ++;
        int pnum = (count / step) % max_people + 1 ;
        pnum = pnum + pnum;
        vector<ofVec2f> poss;
        for(int i = 0; i < pnum; i++) {
            ofVec2f pos( config::ASPECT_RATIO * double( count % step ) / step / 4, ( i + 0.5 ) / pnum );
//            ofVec2f pos( config::ASPECT_RATIO / 4 * ofRandom(1.), ofRandom(1.) );
            poss.push_back(pos);
        }
        return poss;
    }
    
    vector<ofVec2f> getpos_dummy2(){
        static int count = 0;
        const int sec = 10;
        const int step = config::FPS * sec;
        const int max_people = 10;
        count ++;
        int pnum = (count / step) % max_people + 1 ;
        vector<ofVec2f> poss;
        for(int i = 0; i < pnum; i++) {
            ofVec2f pos( config::ASPECT_RATIO * double( count % step ) / step + ofRandom(0.01) ,
                        ( i + 0.5 ) / pnum + ofRandom(0.01));
            poss.push_back(pos);
        }
        for(int i = 0; i < pnum; i++) {
            ofVec2f pos2( config::ASPECT_RATIO * double( count % step ) / step + ofRandom(0.01) -0.5 ,
                         ( i + 0.5 ) / pnum + ofRandom(0.01));
            poss.push_back(pos2);
        }
        return poss;
    }
    
    vector<ofVec2f> main_getpos(){
        return buffer;
    }
    
    vector<ofVec2f> getpos(bool isDummy){
        if(isDummy)
            return getpos_dummy();
        else
            return main_getpos();
    }
    
}