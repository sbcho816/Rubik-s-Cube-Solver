#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Test");

	vidGrabber.setup(1280, 720);
}

//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();

	if (vidGrabber.isFrameNew()) {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofSetColor(255, 255, 255);
	//ofColor green(0, 255, 0);
	//ofSetColor(green);

	//ofDrawRectangle(50, 50, 10, 10);
	//ofDrawRectangle(100, 100, 10, 10);
	//ofDrawRectangle(400, 400, 10, 10);
	// Draw the webcam video
	vidGrabber.draw(0, 0);
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
