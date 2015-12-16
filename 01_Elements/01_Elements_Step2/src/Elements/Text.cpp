#include "Text.h"
#include "ofMain.h"

namespace Elements {
	//----------
	void Text::customDraw() {
		ofPushStyle();
		{
			//find the bounds in coordinates local to this element
			auto localBounds = this->bounds;
			localBounds.x = 0.0f;
			localBounds.y = 0.0f;

			//draw the background fill
			ofFill();
			ofSetColor(255);
			ofDrawRectangle(localBounds);

			//draw an outline
			ofNoFill();
			ofSetColor(0);
			ofSetLineWidth(1.0f);
			ofDrawRectangle(localBounds);

			//draw the text
			ofDrawBitmapString(this->text, 10, 10);
		}
		ofPopStyle();

		ofDrawBitmapString(this->text, 10, 10);
	}
}