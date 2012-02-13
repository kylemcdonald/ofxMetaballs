#pragma once

#include "ofMain.h"

#include "Metaballs.h"

class ofApp : public ofBaseApp{	
public:
	void setup();
	void update();
	void draw();
	
	CMetaballs *m_pMetaballs;
	ofPoint *ballPoints;
	float *ballMasses;
	int nPoints;
	
	ofEasyCam cam;
};

