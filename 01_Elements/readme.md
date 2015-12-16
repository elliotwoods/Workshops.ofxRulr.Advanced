# 01_Elements

## Introducing

* Lambda functions
* `std::function`
* ofxLiquidEvent

## Steps

### 1. Create a `Base` class within the namespace `Elements`

* Give it a property `ofRectangle bounds`.
* Give it methods `customDraw()` and `customMousePressed()`. Make them empty, virtual, protected
* Give it methods `draw()` and `mousePressed(float x, float y)`. Define them to call `customDraw` and `customMousePressed` appropriately
* Create a `vector<shared_ptr<Elements::Base>> elements` within ofApp
* Implement `ofApp::draw` and `ofApp::mousePressed` to work with `elements`.

2. Create classes `Elements::Button` and `Elements::Text`

* Both should inherit `Elements::Base`
* Give both a property called `string text`
* `Text` draws a white background, a black outline and the text string
* `Button` draws a rounded rectangle with a light grey background, a black background and the text string
* `Button` brings up a message box with the string when it is pressed using `ofSystemAlertDialog`
* In `ofApp::setup`, add a `Text` and a `Button` to `ofApp::elements`.

Note : I've noticed on some version of oF, it will ignore the colour when drawing the bitmap string

3. Replace `customMousePressed` / `customDraw` virtual methods with `onMousePressed` / `onDraw` functions in `Elements::Base`

* Add `ofRectangle` as a parameter of `onDraw` to give the `localBounds`.

4. Define a new type of `Element` from within `ofApp::setup`

* Add an ellipse which draws in dark grey. Set its bounds and add it to `ofApp::elements`

5. Replace `function<void(...)>` with `ofxLiquidEvent<...>`

* Change the `Base::draw` and `Base::mousePressed` functions to use `notifyListeners(..)`
* Cange the definitions of `Button` and `Text` to use `+=` notation to add a listener to the event
* Add a listener to `button`'s `onMousePressed` to change the application background

## Style notes

### Inheritance

* Use the `override` keyword in your header file to explicitly override function definitions
* An instance should never store a `shared_ptr` of itself. Use `weak_ptr` in this case.
