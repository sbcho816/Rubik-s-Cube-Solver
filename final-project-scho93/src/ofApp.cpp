#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Test");

	vid_grabber.setup(vid_width, vid_height);
}

//--------------------------------------------------------------
void ofApp::update(){
	vid_grabber.update();

	if (vid_grabber.isFrameNew()) {
		pixel_color = vid_grabber.getPixels().getColor(632, 352);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	
	// Draw the webcam video
	vid_grabber.draw(0, 0);

	ofColor green(0, 255, 0);
	ofSetColor(green);

	ofFill();
	// Draw the center 3 squares.
	ofDrawRectangle(632, 232, 16, 16);
	ofDrawRectangle(632, 352, 16, 16);
	ofDrawRectangle(632, 472, 16, 16);
	// Draw the left 3 squares.
	ofDrawRectangle(512, 232, 16, 16);
	ofDrawRectangle(512, 352, 16, 16);
	ofDrawRectangle(512, 472, 16, 16);
	// Draw the right 3 squares.
	ofDrawRectangle(752, 232, 16, 16);
	ofDrawRectangle(752, 352, 16, 16);
	ofDrawRectangle(752, 472, 16, 16);

	ofSetColor(pixel_color.r, pixel_color.g, pixel_color.b);
	ofDrawRectangle(5, 5, 40, 40);
	//ofDrawBitmapString("This is a test", 30, 30);
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

/*
// Given:
// unsigned char *buffer, an array storing a one-channel image
// int x, the horizontal coordinate (column) of your query pixel
// int y, the vertical coordinate (row) of your query pixel
// int imgWidth, the width of your image

// Now you can GET values at location (x,y), e.g.:
unsigned char pixelValueAtXY = buffer[y*imgWidth + x;];

*/