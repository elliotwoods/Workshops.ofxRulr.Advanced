#include "Text.h"
#include "ofMain.h"

namespace Elements {
	//----------
	Text::Text() {
		this->onDraw += [this](ofRectangle localBounds) {
			ofPushStyle();
			{
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
		};
	}
}