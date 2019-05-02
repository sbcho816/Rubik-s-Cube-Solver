#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Rubik's Cube Solver");

	vid_grabber.setup(vid_width, vid_height);

	code_font.load("CODE", 29);
}

//--------------------------------------------------------------
void ofApp::update(){
	vid_grabber.update();

	if (vid_grabber.isFrameNew()) {
		for (int n = 0; n < 9; n++) {
			average_pixel_color[n] = getAverageColor(n);
			estimated_pixel_color[n] = EstimateColor(average_pixel_color[n]);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	
	// Draw the webcam video.
	vid_grabber.draw(0, 0);

	ofSetColor(ofColor::green);
	ofFill();
	// Draw 9 squares for location of color detection.
	for (int n = 0; n < 9; n++) {
		ofDrawRectangle(getXCoordinate(n), getYCoordinate(n), 16, 16);
	}

	// Draw the estimated colors on the top left.
	int xCoordinate = 5;
	int yCoordinate = 5;
	if (!estimated_pixel_color.empty()) {
		for (int n = 0; n < 9; n++) {
			ofSetColor(estimated_pixel_color[n]);
			ofDrawRectangle(xCoordinate, yCoordinate, 75, 75);
			xCoordinate += 75;
			if (n == 2 || n == 5) {
				xCoordinate = 5;
				yCoordinate += 75;
			}
		}
	}

	// DEBUGGING PURPOSES
	// Draw the original pixel colors next to estimated colors.
	int xxCoordinate = 235;
	int yyCoordinate = 5;
	if (!average_pixel_color.empty()) {
		for (int n = 0; n < 9; n++) {
			ofSetColor(average_pixel_color[n].r, average_pixel_color[n].g, average_pixel_color[n].b);
			ofDrawRectangle(xxCoordinate, yyCoordinate, 75, 75);
			xxCoordinate += 75;
			if (n == 2 || n == 5) {
				xxCoordinate = 235;
				yyCoordinate += 75;
			}
		}
	}

	ofSetColor(ofColor::black);
	// Draw lines to make 3x3 grid on top left.
	ofDrawRectangle(79, 5, 2, 225);
	ofDrawRectangle(154, 5, 2, 225);
	ofDrawRectangle(5, 79, 225, 2);
	ofDrawRectangle(5, 154, 225, 2);

	ofDrawRectangle(5, 5, 1, 225);
	ofDrawRectangle(229, 5, 1, 225);
	ofDrawRectangle(5, 5, 225, 1);
	ofDrawRectangle(5, 229, 225, 1);

	ofSetColor(255, 255, 255);
	if (!reset) {
		// Draw the cube layout of the captured sides.
		if (space_key_count == 1 && !green_captured) {
			green_side.grabScreen(5, 5, 225, 225);
			green_captured = true;
		}
		green_side.draw(120, 450, 100, 100);

		if (space_key_count == 2 && !red_captured) {
			red_side.grabScreen(5, 5, 225, 225);
			red_captured = true;
		}
		red_side.draw(220, 450, 100, 100);

		if (space_key_count == 3 && !blue_captured) {
			blue_side.grabScreen(5, 5, 225, 225);
			blue_captured = true;
		}
		blue_side.draw(320, 450, 100, 100);

		if (space_key_count == 4 && !orange_captured) {
			orange_side.grabScreen(5, 5, 225, 225);
			orange_captured = true;
		}
		orange_side.draw(20, 450, 100, 100);

		if (space_key_count == 5 && !yellow_captured) {
			yellow_side.grabScreen(5, 5, 225, 225);
			yellow_captured = true;
		}
		yellow_side.draw(120, 550, 100, 100);

		if (space_key_count == 6 && !white_captured) {
			white_side.grabScreen(5, 5, 225, 225);
			white_captured = true;
		}
		white_side.draw(120, 350, 100, 100);
	}

	ofSetColor(200, 200, 200);
	if (sol != nullptr) {
		string str_sol = string(sol);
		// Prints the solution centered to the screen.
		code_font.drawString(str_sol, 640 - (code_font.stringWidth(str_sol) / 2), 694);
	} else if (unsolvable) {
		code_font.drawString("Unsolvable cube!", 640 - (code_font.stringWidth("Unsolvable cube!") / 2), 694);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		reset = false;
		space_key_count++;
		FillCubeString();
	}
	if (key == 'R' || key == 'r') {
		reset = true;
		space_key_count = 0;

		white_captured = false;
		yellow_captured = false;
		red_captured = false;
		orange_captured = false;
		green_captured = false;
		blue_captured = false;

		white_side.clear();
		yellow_side.clear();
		red_side.clear();
		orange_side.clear();
		green_side.clear();
		blue_side.clear();

		up.clear();
		right.clear();
		front.clear();
		down.clear();
		left.clear();
		back.clear();

		sol = nullptr;
		unsolvable = false;
	}
	if (key == 'S' || key == 's') {
		PrintSolution();
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

/*
* Color difference algorithm taken from https://www.compuphase.com/cmetric.htm.
* Computes the closeness of two colors using RGB values.
*/
double ofApp::ColorDifference(const ofColor cube_color, const ofColor input_color) {
	double r_mean = (cube_color.r + input_color.r) / 2.0;
	double r = cube_color.r - input_color.r;
	double g = cube_color.g - input_color.g;
	double b = cube_color.b - input_color.b;
	return sqrt((2 + r_mean / 256.0) * r * r + 4 * g * g + (2 + (255 - r_mean) / 256.0) * b * b);
}

ofColor ofApp::EstimateColor(const ofColor input_color) {
	double min_difference = ColorDifference(compare_colors[0], input_color);
	ofColor estimate_color = compare_colors[0];

	for (ofColor color : compare_colors) {
		if (ColorDifference(color, input_color) < min_difference) {
			min_difference = ColorDifference(color, input_color);
			estimate_color = color;
		}
	}

	if (estimate_color == compare_white) {
		return display_white;
	} else if (estimate_color == compare_yellow) {
		return display_yellow;
	} else if (estimate_color == compare_red) {
		return display_red;
	} else if (estimate_color == compare_orange) {
		return display_orange;
	} else if (estimate_color == compare_green) {
		return display_green;
	} else {
		return display_blue;
	}
}

void ofApp::FillCubeString() {
	if (space_key_count == 1) {
		ColorToString(front);
	} else if (space_key_count == 2) {
		ColorToString(right);
	} else if (space_key_count == 3) {
		ColorToString(back);
	} else if (space_key_count == 4) {
		ColorToString(left);
	} else if (space_key_count == 5) {
		ColorToString(down);
	} else if (space_key_count == 6) {
		ColorToString(up);
	}
}

void ofApp::ColorToString(string& face) {
	for (int n = 0; n < 9; n++) {
		if (estimated_pixel_color[n] == display_white) {
			face += "U";
		} else if (estimated_pixel_color[n] == display_yellow) {
			face += "D";
		} else if (estimated_pixel_color[n] == display_red) {
			face += "R";
		} else if (estimated_pixel_color[n] == display_orange) {
			face += "L";
		} else if (estimated_pixel_color[n] == display_green) {
			face += "F";
		} else if (estimated_pixel_color[n] == display_blue) {
			face += "B";
		}
	}
}

void ofApp::PrintSolution() {
	if (space_key_count >= 6) {
		string cube_definition = up + right + front + down + left + back;
		facelets = &cube_definition[0u]; // Converts string to mutable char*.
		sol = solution(facelets, 24, 1000, 0, "cache");
		if (sol == nullptr) {
			unsolvable = true;
		}
	}
}
