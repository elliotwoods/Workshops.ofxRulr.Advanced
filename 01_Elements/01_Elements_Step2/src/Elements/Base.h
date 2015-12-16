#pragma once

#include "ofRectangle.h"

namespace Elements {
	class Base {
	public:
		void draw();
		void mousePressed(float x, float y);

		ofRectangle bounds;
	protected:
		virtual void customDraw() { }
		virtual void customMousePressed() { }
	};
}