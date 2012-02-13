#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
	nPoints = 32;
	ballPoints = new ofPoint[nPoints];
	ballMasses = new float[nPoints];
	m_pMetaballs.SetGridSize(128);
}

void ofApp::update(){
}

void ofApp::draw(){
	float massBase = .3; //ofMap(mouseY, 0, ofGetHeight(), .001, 1, true);
	for (int i = 0; i < nPoints; i++){
		float offset = (i + 1) * .01;
		float bx = ofSignedNoise(ofGetElapsedTimef() + offset, 0, 0);
		float by = ofSignedNoise(0, ofGetElapsedTimef() + offset, 0);
		float bz = ofSignedNoise(0, 0, ofGetElapsedTimef() + offset);
		ballPoints[i].set(bx,by,bz);
		ballMasses[i] = massBase;
	}
	m_pMetaballs.UpdateBallsFromPointsAndMasses (nPoints, ballPoints, ballMasses);

	ofBackground(0);
	
	cam.begin();
	glEnable(GL_DEPTH_TEST);
	ofScale(256, 256, 256);
	ofNoFill();
	ofBox(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	m_pMetaballs.Render();
	cam.end();
	
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
}
