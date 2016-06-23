#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    //    ofAppGLFWWindow window;
    //    window.setMultiDisplayFullscreen(true);
    //    ofSetupOpenGL(&window,1024,768,OF_WINDOW);

    // <-------- setup the GL context
    ofSetupOpenGL(1024,768,OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
    
    
    
//    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
//    
//    ofxMultiGLFWWindow glfw;
//    glfw.setOpenGLVersion(3,2); // must be set
//    
//    glfw.windowCount = 2;
//	ofSetupOpenGL(&glfw,1024,768,OF_WINDOW);
//    
//	ofRunApp(new ofApp());
}
