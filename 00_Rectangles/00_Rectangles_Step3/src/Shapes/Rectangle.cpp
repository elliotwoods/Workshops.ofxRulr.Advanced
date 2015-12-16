#include "Rectangle.h"

#include "ofMain.h"

namespace Shapes {
	//----------
	void Rectangle::draw() const {
		ofPushStyle();
		{
			ofSetColor(color);
			ofDrawRectangle(bounds);
		}
		ofPopStyle();
	}
}
