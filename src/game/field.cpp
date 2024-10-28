#include <cstring>

#include "field.hpp"
#include "symbols.hpp"

void Field::Clear() {
	memset(fld, SYMBOL_FIELD, sizeof(fld));
}

Field::Field() {
	Clear();
}

void Field::Burning() {
	for(int j = FIELD_HEIGHT; j >= 0; j--) {
		static bool fillLine;
		fillLine = true;

		for(int i = 0; i < FIELD_WIDTH-1; i++)
			if(fld[j][i] != SYMBOL_FIGURE_DOWN)
				fillLine = false;
		
		if(fillLine) {
			for(int y = j; y >= 1; y--)
				memcpy(fld[y], fld[y-1], sizeof(fld[y]));
			return;
		}
	}
}

void Field::PutToScreen(ScreenMap &scr) {
	for(int i = 0; i < FIELD_WIDTH; i++)
		for(int j = 0; j < FIELD_HEIGHT; j++)
			scr[j][i*2] = scr[j][i*2+1] = fld[j][i];
}

