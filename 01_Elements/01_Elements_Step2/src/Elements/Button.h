#pragma once

#include "Base.h"

namespace Elements {
	class Button : public Base {
	public:
		string text;
	protected:
		void customDraw() override;
		void customMousePressed() override;
	};
}