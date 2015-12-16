#pragma once

#include "ofRectangle.h"
#include <functional>

namespace Elements {
	class Base {
	public:
		void draw();
		void mousePressed(float x, float y);

		function<void(ofRectangle)> onDraw;
		function<void()> onMousePressed;

		ofRectangle bounds;
	protected:
	};
}