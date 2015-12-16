# 02_ofxCvGui

## Introducing

* ofxCvGui

## Steps

### 1. Include all the necessary addons for ofxCvGui

* ofxAssets
* ofxCvGui
* ofxGrabCam
* ofxLiquidEvent
* ofxSingleton
* ofxTextInputField

### 2. Build a GUI with a single panel showing the current camera feed

* Include "ofxCvGui.h"
* In `ofApp` add `ofxCvGui::Builder gui`
* In `ofApp` add `ofVideoGrabber video`
* In `ofApp::setup()` call `this->video.initGrabber(1280, 720)`
* In `ofApp::setup()` call `this->gui.init()`
* In `ofApp::setup()` call `this->gui.add(this->video, "Camera")` to add a panel for the camera
* In `ofApp::update()` call `this->video.update()`
* Note the 1:1 and Stretch zoom functions and the navigator
* Note 'f' to toggle fullscreen

### 3. Add a second panel with an inverse image

* Add `ofImage inverted` to `ofApp`
* Add `inverted` to the gui
* Calculate the inverted image (tip : use `for(auto & pixel : this->video.getPixels()) {...}`)
* Note 'm' to maximise a panel

### 4. Add an instuctions panel

* Add `this->gui.addInstructions()`
* Make an `instructions.txt` file in your `bin/data` folder and add some notes there

## Style notes

### Including addons

* With Visual Studio we include the addons as projects rather than as bare files (this helps keep them up to date with any latest changes, and can improve build speeds).
