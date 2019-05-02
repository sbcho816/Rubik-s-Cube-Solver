#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <string>
#include <vector>
#include <cmath>

// Kociemba solving algorithm taken from https://github.com/muodov/kociemba.
extern "C" {
#include "kociemba/include/search.h"
}

using std::string;
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

		ofTrueTypeFont code_font;

		int space_key_count = 0;
		int s_key_count = 0;
		int r_key_count = 0;

		bool reset = false;

		// Rubik's Cube RGB values inspired from https://www.schemecolor.com/rubik-cube-colors.php.
		// Colors to be compared with input color.
		const ofColor compare_white = ofColor(224, 224, 224);
		const ofColor compare_yellow = ofColor(255, 213, 0);
		const ofColor compare_red = ofColor(200, 0, 0);
		const ofColor compare_orange = ofColor(255, 85, 0);
		const ofColor compare_green = ofColor(0, 155, 50);
		const ofColor compare_blue = ofColor(0, 69, 173);

		// Cube colors displayed on screen.
		const ofColor display_white = ofColor(255, 255, 255);
		const ofColor display_yellow = ofColor(255, 255, 0);
		const ofColor display_red = ofColor(225, 0, 0);
		const ofColor display_orange = ofColor(255, 170, 0);
		const ofColor display_green = ofColor(0, 185, 0);
		const ofColor display_blue = ofColor(0, 0, 200);

		const vector<ofColor> compare_colors = { compare_white, compare_yellow, compare_red,
												 compare_orange, compare_green, compare_blue };

		vector<ofColor> average_pixel_color = vector<ofColor>(9);
		vector<ofColor> estimated_pixel_color = vector<ofColor>(9);

		ofImage white_side;
		ofImage yellow_side;
		ofImage red_side;
		ofImage orange_side;
		ofImage green_side;
		ofImage blue_side;

		bool white_captured = false;
		bool yellow_captured = false;
		bool red_captured = false;
		bool orange_captured = false;
		bool green_captured = false;
		bool blue_captured = false;

		string up;
		string right;
		string front;
		string down;
		string left;
		string back;

		char* facelets;
		char* sol;

		bool unsolvable = false;

		int getXCoordinate(int n);
		int getYCoordinate(int n);
		ofColor getAverageColor(int n);
		ofColor ComputeAverageColor(int xBegin, int xEnd, int yBegin, int yEnd);
		double ColorDifference(const ofColor default_color, const ofColor input_color);
		ofColor EstimateColor(const ofColor input_color);
		void FillCubeString();
		void ColorToString(string& face);
		void PrintSolution();
};
