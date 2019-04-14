#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <iostream>
#include <vector>

using std::vector;

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

		ofVideoGrabber vid_grabber;
		int vid_width = 1280;
		int vid_height = 720;

		vector<ofColor> average_pixel_color = vector<ofColor>(9);

		int getXCoordinate(int n);
		int getYCoordinate(int n);
		ofColor getAverageColor(int n);
		ofColor ComputeAverageColor(int xBegin, int xEnd, int yBegin, int yEnd);
};
