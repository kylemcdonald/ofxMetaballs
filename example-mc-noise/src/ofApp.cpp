#include "ofApp.h"

void ofApp::setup() {
	ofSeedRandom(0);
	ofSetVerticalSync(true);

	iso.setup(32);
	
	vector<ofVec3f> centers;
	for(int i = 0; i < 5; i++) {
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
		iso.setRadius(mouseX / (float) ofGetWidth(), (mouseX + mouseY) / (float) ofGetHeight());
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