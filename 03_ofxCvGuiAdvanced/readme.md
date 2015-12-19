# 02_ofxCvGuiAdvanced

## Introducing

* Widgets
* Adding `Element`s to `Panel`s
* 3D panels


## Steps

### 0. Include all the necessary addons for ofxCvGui

* ofxAssets
* ofxCvGui
* ofxGrabCam
* ofxLiquidEvent
* ofxSingleton
* ofxTextInputField

### 1. Add a `World ` and a `Scroll` panel

* Add a `gui` instance to `ofApp`
* In `ofApp::setup` call `gui->init()`
* In `ofApp::setup` call `gui->addWorld()`
* In `ofApp::setup` call `gui->addScroll()`
* Give them both captions

### 2. Draw a sphere and make some controls for it

* Make a class Sphere
* Add an array of float parameters `ofParameter<float> xyz[3]`
* Add parameters for radius and hue
* Add a constructor which sets up the parameters
* Add a `vector<Sphere> spheres` to `ofApp`
* Write a draw function for `Sphere`
* In `ofApp::setup` make 10 spheres
* In `ofApp::setup` add a lister to draw the spheres on the `World` panel

### 3. Add widgets for all the spheres

* In `ofApp::setup` get a pointer to the new scroll panel we're creating
* For each sphere add a title to the widgets panel `        widgets->add(ofxCvGui::Widgets::Title::make("Sphere"));`
* Use similar syntax to add the parameters of the spheres to the widgets panel
* Play with the result

### 4. Define HAS_OFXGRABCAM

These instructions are for mac. For Windows this will happen automatically if you use the `ofxCvGuiLib` project and property sheets.

*  : go to project Build Settings
* Go to 'All' not 'Basic'
* Add `HAS_OFXGRABCAM` to `Preprocessor Macros`


### Including addons
