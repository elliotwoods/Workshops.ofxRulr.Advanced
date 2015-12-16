#include "Button.h"
#include "ofMain.h"

namespace Elements {
	//----------
	Button::Button() {
		this->onDraw += [this](ofRectangle localBounds) {
			ofPushStyle();
			{
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
		};

		this->onMousePressed += [this]() {
			ofSystemAlertDialog(this->text);
		};
	}
}