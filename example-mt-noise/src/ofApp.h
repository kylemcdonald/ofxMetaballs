#pragma once

#include "ofMain.h"

#include "ofxMetaball.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	MarchingTetrahedrons iso;
	ofEasyCam cam;
};
