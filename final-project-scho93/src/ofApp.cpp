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
		for (int n = 0; n < 9; n++) {
			average_pixel_color[n] = getAverageColor(n);
		}
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
	for (int n = 0; n < 9; n++) {
		ofDrawRectangle(getXCoordinate(n), getYCoordinate(n), 16, 16);
	}

	int xCoordinate = 5;
	int yCoordinate = 5;
	if (!average_pixel_color.empty()) {
		for (int n = 0; n < 9; n++) {
			ofSetColor(average_pixel_color[n].r, average_pixel_color[n].g, average_pixel_color[n].b);
			ofDrawRectangle(xCoordinate, yCoordinate, 75, 75);
			xCoordinate += 75;
			if (n == 2 || n == 5) {
				xCoordinate = 5;
				yCoordinate += 75;
			}
		}
	}

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

// Gets the x-coordinate of the green square. Parameter is the square number.
int ofApp::getXCoordinate(int n) {
	if (n % 3 == 0) {
		return 512;
	} else if (n % 3 == 1) {
		return 632;
	} else {
		return 752;
	}
}

// Gets the y-coordinate of the green square. Parameter is the square number.
int ofApp::getYCoordinate(int n) {
	if (n <= 2) {
		return 232;
	} else if (n >= 3 && n <= 5) {
		return 352;
	} else {
		return 472;
	}
}

// Gets the average color within the green square. Parameter is the square nunumber.
ofColor ofApp::getAverageColor(int n) {
	switch (n) {
		case 0: {
			return ComputeAverageColor(512, 528, 232, 248);
		}
		case 1: {
			return ComputeAverageColor(632, 648, 232, 248);
		}
		case 2: {
			return ComputeAverageColor(752, 768, 232, 248);
		}
		case 3: {
			return ComputeAverageColor(512, 528, 352, 368);
		}
		case 4: {
			return ComputeAverageColor(632, 648, 352, 368);
		}
		case 5: {
			return ComputeAverageColor(752, 768, 352, 368);
		}
		case 6: {
			return ComputeAverageColor(512, 528, 472, 488);
		}
		case 7: {
			return ComputeAverageColor(632, 648, 472, 488);
		}
		case 8: {
			return ComputeAverageColor(752, 768, 472, 488);
		}
	}
}

ofColor ofApp::ComputeAverageColor(int x_begin, int x_end, int y_begin, int y_end) {
	int counter = 0;

	int red_count = 0;
	int green_count = 0;
	int blue_count = 0;

	int avg_red_value;
	int avg_green_value;
	int avg_blue_value;

	for (int x = x_begin; x < x_end; x++) {
		for (int y = y_begin; y < y_end; y++) {
			red_count += vid_grabber.getPixels().getColor(x, y).r;
			green_count += vid_grabber.getPixels().getColor(x, y).g;
			blue_count += vid_grabber.getPixels().getColor(x, y).b;
			counter++;
		}
	}
	avg_red_value = red_count / counter;
	avg_green_value = green_count / counter;
	avg_blue_value = blue_count / counter;
	return ofColor(avg_red_value, avg_green_value, avg_blue_value);
}

// Debating whether to use hue or RGB for color difference.
// https://stackoverflow.com/questions/35113979/calculate-distance-between-colors-in-hsv-space