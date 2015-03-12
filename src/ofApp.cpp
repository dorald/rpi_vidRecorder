#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    frameCounter = 0;
    
    ofSetFrameRate(30);

    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    fbo.allocate(vidGrabber.getWidth(), vidGrabber.getHeight());
    pix.allocate(vidGrabber.getWidth(), vidGrabber.getHeight(), OF_IMAGE_COLOR);
    gifEncoder.setup(vidGrabber.getWidth(), vidGrabber.getHeight(), .25, 256);
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
    
    fileName = "/mnt/storage/rpitest";

    
    ofSetWindowShape(vidGrabber.getWidth(), vidGrabber.getHeight()	);
    bRecording = false;
    ofEnableAlphaBlending();
    
    reader.setAsync(true);
    
}

void ofApp::exit() {
//    vidRecorder.close();
    gifEncoder.exit();
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew() && bRecording){
        frameCounter++;
//        vidRecorder.addFrame(vidGrabber.getPixelsRef());
    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::captureFrame() {
    
    reader.readToPixels(fbo, pix);
    //        gifsaver.append(pix);
    gifEncoder.addFrame(pix.getPixels(), fbo.getWidth(), fbo.getHeight());
    

    
}


//--------------------------------------------------------------
void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    
    fbo.begin();
    vidGrabber.draw(0, 0);
    fbo.end();
    
    fbo.draw(0,0);

    if(bRecording){
        ofSetColor(255, 0, 0);
        ofCircle(ofGetWidth() - 20, 20, 5);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            captureFrame();
            break;
        case 's':
            cout <<"start saving\n" << endl;
            gifEncoder.save("test.gif");
            break;
        default:
            break;
    }

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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
