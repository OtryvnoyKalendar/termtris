#pragma once

#include "init.hpp"

class Field {
public:
	FieldMap fld;
	Field();
	void Clear();
	void PutToScreen(ScreenMap &scr);
	void Burning();
};

extern Field field;

