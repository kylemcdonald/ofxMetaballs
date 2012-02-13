#pragma once

#include "ofMain.h"

#include "MarchingCubes.h"

class ofApp : public ofBaseApp{	
public:
	void setup();
	void update();
	void draw();
	
	MarchingCubes m_pMetaballs;
	ofPoint *ballPoints;
	float *ballMasses;
	int nPoints;
	
	ofEasyCam cam;
};

