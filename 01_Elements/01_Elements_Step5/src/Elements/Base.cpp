#include "Base.h"

#include "ofMain.h"

namespace Elements {
	//----------
	void Base::draw() {
		//translate to local coordinates
		ofPushMatrix();
		{
			ofTranslate(this->bounds.getTopLeft());

			//calculate the bounds within coordinates local to this element
			auto localBounds = this->bounds;
			localBounds.x = 0.0f;
			localBounds.y = 0.0f;

			//call all draw listeners
			this->onDraw.notifyListeners(localBounds);
		}
		ofPopMatrix();
	}

	//----------
	void Base::mousePressed(float x, float y) {
		//if mouse landed inside our bounds
		if (this->bounds.inside(ofVec2f(x, y))) {
			//call all listeners to mouse pressed event
			this->onMousePressed.notifyListeners();
		}
	}
}