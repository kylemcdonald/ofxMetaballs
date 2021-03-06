#include "ofApp.h"

void ofApp::setup() {
	ofSeedRandom(0);
	ofSetVerticalSync(true);

	iso.setup(64);
	
	vector<ofVec3f> centers;
	for(int i = 0; i < 12; i++) {
		centers.push_back(ofVec3f(ofRandomuf(), ofRandomuf(), ofRandomuf()));
	}
	iso.setCenters(centers);
	iso.setRadius(8/32., 16./32.);
	iso.update();
	
	ofMesh mesh = iso.getMesh();
	mesh.save("out-ascii.ply", false);
	mesh.save("out-binary.ply", true);
}  

void ofApp::update() {
	if(ofGetKeyPressed()) {
		float minRadius = mouseX / (float) ofGetWidth();
		float maxRadius = (mouseY) / (float) ofGetHeight();
		iso.setRadius(minRadius, minRadius + maxRadius);
		iso.update();
	}
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofScale(400, 400, 400);
	iso.draw();
	cam.end();
	
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
}