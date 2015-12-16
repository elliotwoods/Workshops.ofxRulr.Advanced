#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	this->video.initGrabber(1280, 720);

	this->gui.init();
	this->gui.addInstructions();
	this->gui.add(this->video, "Camera");
	this->gui.add(this->inverted, "Inverted");
}

//--------------------------------------------------------------
void ofApp::update(){
	this->video.update();

	//if we have a new video frame
	if (this->video.isFrameNew()) {
		//calculate the inverse
		this->inverted = this->video.getPixels();
		for (auto & pixel : this->inverted.getPixels()) {
			pixel = 255 - pixel;
		}

		// push the texture to gpu
		this->inverted.update(); 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

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
