#include "Button.h"
#include "ofMain.h"

namespace Elements {
	//----------
	void Button::customDraw() {
		ofPushStyle();
		{
			//find the bounds in coordinates local to this element
			auto localBounds = this->bounds;
			localBounds.x = 0.0f;
			localBounds.y = 0.0f;

			//draw the background fill
			ofFill();
			ofSetColor(200);
			ofDrawRectRounded(localBounds, 5);

			//draw an outline
			ofNoFill();
			ofSetColor(0);
			ofSetLineWidth(1.0f);
			ofDrawRectRounded(localBounds, 5);

			//draw the text
			ofDrawBitmapString(this->text, 15, 15);
		}
		ofPopStyle();

		ofDrawBitmapString(this->text, 15, 15);
	}

	//----------
	void Button::customMousePressed() {
		ofSystemAlertDialog(this->text);
	}
}