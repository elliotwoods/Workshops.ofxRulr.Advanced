#include "Base.h"

#include "ofMain.h"

namespace Elements {
	//----------
	void Base::draw() {
		//translate to local coordinates
		ofPushMatrix();
		{
			ofTranslate(this->bounds.getTopLeft());

			//check if we have a draw function
			if (this->onDraw) {
				//calculate the bounds within coordinates local to this element
				auto localBounds = this->bounds;
				localBounds.x = 0.0f;
				localBounds.y = 0.0f;

				//call the draw function
				this->onDraw(localBounds);
			}
		}
		ofPopMatrix();
	}

	//----------
	void Base::mousePressed(float x, float y) {
		//if mouse landed inside our bounds
		if (this->bounds.inside(ofVec2f(x, y))) {
			//check if we have a function setup for when mouse is pressed
			if (this->onMousePressed) {
				//call the function
				this->onMousePressed();
			}
		}
	}
}