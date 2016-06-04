#pragma once

#include "ofMain.h"
#include "kuroda.h"
#include "suzuki.h"
#include "ito.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
     //kuroda
    kuroda* kuroda_;
    
    //suzuki
    suzuki* suzuki_;
    
    //ito
    ito* ito_;
    
    //time
    float timeStamp, time;
    int mode;
    const float time0to1 = 2,
                time1to2 = 2,
                time2to3 = 2,
                time01   = time0to1,
                time02   = time01 + time1to2,
                time03   = time02 + time2to3;
};
