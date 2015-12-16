#pragma once

#include "Base.h"

namespace Elements {
	class Text : public Base {
	public:
		string text;
	protected:
		void customDraw() override;
	};
}