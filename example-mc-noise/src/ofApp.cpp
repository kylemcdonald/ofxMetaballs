#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	iso.setup(32);
	light.enable();
	light.setPosition(500, 0, 0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
}  

void ofApp::update() {
	if(ofGetFrameNum() == 0 || ofGetKeyPressed()) {
		vector<ofVec3f> centers;
		for(int i = 0; i < 500; i++) {
			centers.push_back(ofVec3f(ofRandomf(), ofRandomf(), ofRandomf()));
		}
		iso.setCenters(centers);
		iso.setRadius(mouseX / (float) ofGetWidth(), (mouseX + mouseY) / (float) ofGetHeight());
		iso.update();
	}
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofEnableLighting();
	ofScale(200, 200, 200);
	iso.draw();
	ofDisableLighting();
	cam.end();
	
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
}