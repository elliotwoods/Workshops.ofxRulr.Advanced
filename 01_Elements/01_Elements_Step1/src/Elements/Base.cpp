#include "Base.h"

#include "ofMain.h"

namespace Elements {
	//----------
	void Base::draw() {
		//translate to local coordinates
		ofPushMatrix();
		{
			ofTranslate(this->bounds.getTopLeft());

			//then call the custom draw function
			this->customDraw();
		}
		ofPopMatrix();
	}

	//----------
	void Base::mousePressed(float x, float y) {
		//if mouse landed inside our bounds
		if (this->bounds.inside(ofVec2f(x, y))) {
			//then call our custom mouse pressed function
			this->customMousePressed();
		}
	}
}