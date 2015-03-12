#pragma once

#include "ofMain.h"
#include "ofxFastFboReader.h"
#include "ofxGifEncoder.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void exit();
    
    
    ofVideoGrabber      vidGrabber;
    //ofxVideoRecorder    vidRecorder;
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    
    ofxFastFboReader reader;
    int frameCounter;
    
    ofFbo fbo;
    ofImage image;
    ofPixels pix;
    
    void onGifSaved(string & fileName);
    void captureFrame();
    
    vector <ofTexture *> txs; // for previewing
    vector <ofxGifFrame *> pxs;
    
    int frameW, frameH;
    int nFrames;
    
    ofVideoGrabber vid;
    ofxGifEncoder gifEncoder;
    
    
    
    
		
};
