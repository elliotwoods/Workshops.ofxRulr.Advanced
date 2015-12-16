#pragma once

#include "ofxLiquidEvent.h"
#include "ofRectangle.h"

namespace Elements {
	class Base {
	public:
		void draw();
		void mousePressed(float x, float y);

		ofxLiquidEvent<ofRectangle> onDraw;
		ofxLiquidEvent<void> onMousePressed;

		ofRectangle bounds;
	protected:
	};
}