#include "ofApp.h"

#pragma mark Sphere
//-------------------------------------------------------------
Sphere::Sphere() {
    this->xyz[0].set("X", ofRandom(-10.0f, 10.0f), -10, +10);
    this->xyz[1].set("Y", ofRandom(-10.0f, 10.0f), -10, +10);
    this->xyz[2].set("Z", ofRandom(-10.0f, 10.0f), -10, +10);
    this->radius.set("Radius", ofRandom(1.0f), 0.0f, 10.0f);
    this->hue.set("Hue", ofRandom(360.0f), 0.0f, 360.0f);
}

void Sphere::draw() {
    ofPushStyle();
    {
        auto col = ofColor(200, 100, 100);
        col.setHue(this->hue);
        ofSetColor(col);
        ofDrawSphere(this->xyz[0], this->xyz[1], this->xyz[2], this->radius);
    }
    ofPopStyle();
}

#pragma mark ofApp
//--------------------------------------------------------------
void ofApp::setup(){
    this->gui.init();
    auto world = this->gui.addWorld("World");
    this->gui.addScroll("Widgets");
    
    
    this->spheres.resize(10);
    
    world->onDrawWorld += [this](ofCamera &) {
        for(auto & sphere : this->spheres) {
            sphere.draw();
        }
    };
}

//--------------------------------------------------------------
void ofApp::update(){

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
