#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetCircleResolution(100);

	auto text = make_shared<Elements::Text>();
	text->text = "Text";
	text->bounds = ofRectangle(100, 100, 100, 20);
	this->elements.push_back(text);

	auto button = make_shared<Elements::Button>();
	button->text = "Button";
	button->bounds = ofRectangle(300, 100, 100, 20);
	button->onMousePressed += []() {
		ofBackground(ofGetElapsedTimeMillis() % 150 + 100);
	};
	this->elements.push_back(button);

	auto ellipse = make_shared<Elements::Base>();
	ellipse->onDraw += [ellipse](ofRectangle bounds) { //we shouldn't do this (pass the shared_ptr into itself). we should use weak_ptr here
		ofPushStyle();
		{
			ofSetColor(100);
			ofEllipse(bounds.getCenter(), bounds.getWidth(), bounds.getHeight());
		}
		ofPopStyle();
	};
	ellipse->bounds = ofRectangle(100, 200, 200, 100);
	this->elements.push_back(ellipse);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto element : this->elements) {
		element->draw();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (auto element : this->elements) {
		element->mousePressed(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
