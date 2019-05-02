#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../src/ofApp.h"

ofApp app;

// Tests for color estimation.
TEST_CASE("White color detection test") {
	REQUIRE(app.EstimateColor(ofColor::white) == app.display_white);
	REQUIRE(app.EstimateColor(ofColor(235, 235, 235)) == app.display_white);
	REQUIRE(app.EstimateColor(ofColor(224, 224, 224)) == app.display_white);
	REQUIRE(app.EstimateColor(ofColor(210, 210, 210)) == app.display_white);
}

TEST_CASE("Yellow color detection test") {
	REQUIRE(app.EstimateColor(ofColor::yellow) == app.display_yellow);
	REQUIRE(app.EstimateColor(ofColor(255, 255, 102)) == app.display_yellow);
	REQUIRE(app.EstimateColor(ofColor(220, 220, 0)) == app.display_yellow);
}

TEST_CASE("Red color detection test") {
	REQUIRE(app.EstimateColor(ofColor::red) == app.display_red);
	REQUIRE(app.EstimateColor(ofColor(255, 51, 51)) == app.display_red);
	REQUIRE(app.EstimateColor(ofColor(204, 0, 0)) == app.display_red);
}

TEST_CASE("Orange color detection test") {
	REQUIRE(app.EstimateColor(ofColor::orange) == app.display_orange);
	REQUIRE(app.EstimateColor(ofColor(204, 102, 0)) == app.display_orange);
	REQUIRE(app.EstimateColor(ofColor(255, 128, 0)) == app.display_orange);
}

TEST_CASE("Green color detection test") {
	REQUIRE(app.EstimateColor(ofColor::green) == app.display_green);
	REQUIRE(app.EstimateColor(ofColor(0, 204, 0)) == app.display_green);
	REQUIRE(app.EstimateColor(ofColor(0, 153, 0)) == app.display_green);
}

TEST_CASE("Blue color detection test") {
	REQUIRE(app.EstimateColor(ofColor::blue) == app.display_blue);
	REQUIRE(app.EstimateColor(ofColor(0, 0, 200)) == app.display_blue);
	REQUIRE(app.EstimateColor(ofColor(0, 0, 153)) == app.display_blue);
}
