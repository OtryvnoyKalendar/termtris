#include <cstring>

#include "graphic.hpp"
#include "screen.hpp"
#include "symbols.hpp"
#include "conscore.hpp"

void Screen::Clear() {
	memset(scr, SYMBOL_EMPTY, sizeof(scr));
}

Screen::Screen() {
	Clear();
}

void Screen::Show() {
	for(int i = 0; i < console.height; i++)
		for(int j = 0; j < console.width; j++) {
			int color = COLOR_GREEN;
			char symbol = scr[i][j];

			switch(symbol) {
				case SYMBOL_FIGURE:
					color = COLOR_FIGURE; break;
				case SYMBOL_FIGURE_DOWN:
					color = COLOR_FIGURE_DOWN; break;
				case SYMBOL_FIELD:
					color = COLOR_FIELD; break;
			}

			PutSymbolToConsole(i+1, j+1, symbol, color);
		}
}

