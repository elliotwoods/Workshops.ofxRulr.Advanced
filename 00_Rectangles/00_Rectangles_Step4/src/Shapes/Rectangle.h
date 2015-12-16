#pragma once

#include "ofRectangle.h"
#include "ofColor.h"

namespace Shapes {
	struct Rectangle {
		void draw() const;

		ofRectangle bounds;
		ofColor color;
	};
}
