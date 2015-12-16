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

	auto selection = this->selection.lock();
	if (selection) {
		ofPushStyle();
		{
			ofNoFill();
			ofSetLineWidth(2.0f);
			ofSetColor(ofGetElapsedTimeMillis() % 255);
			ofDrawRectangle(selection->bounds);
		}
		ofPopStyle();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_BACKSPACE) {
		auto selection = this->selection.lock();
		if (selection) {
			auto findRectangleInVector = std::find(this->rectangles.begin(), this->rectangles.end(), selection);
			if (findRectangleInVector != this->rectangles.end()) {
				this->rectangles.erase(findRectangleInVector);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	this->selection.reset();

	//go through the rectangles in reverse order (last = top)
	for (auto it = this->rectangles.rbegin(); it != this->rectangles.rend(); it++) {
		auto rectangle = *it;
		if (rectangle) {
			if (rectangle->bounds.inside(ofVec2f(x, y))) {
				//set the selection to the rectangle
				this->selection = rectangle;

				//stop iterating through the list
				break;
			}
		}
	}

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
	newColor.setHue(fmod(ofGetElapsedTimef() * 360.0f, 360.0f));

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
