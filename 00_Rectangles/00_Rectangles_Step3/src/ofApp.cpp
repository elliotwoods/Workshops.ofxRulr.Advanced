#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto & rectangle : rectangles) {
		rectangle->draw();
	}
	if (this->newRectangle) {
		newRectangle->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (this->newRectangle) {
		auto & bounds = newRectangle->bounds;
		bounds.width = x - bounds.x;
		bounds.height = y - bounds.y;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofColor newColor(200, 100, 100);
	newColor.setHue(fmod(ofGetElapsedTimef() * 30.0f, 360.0f));

	this->newRectangle = make_shared<Shapes::Rectangle>();
	this->newRectangle->color = newColor;
	this->newRectangle->bounds = ofRectangle(x, y, 0, 0);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (this->newRectangle) {
		auto & bounds = newRectangle->bounds;
		bounds.width = x - bounds.x;
		bounds.height = y - bounds.y;

		this->rectangles.push_back(newRectangle);
		newRectangle.reset();
	}
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
