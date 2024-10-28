#include <cstring>

#include "figure.hpp"
#include "conscore.hpp"
#include "symbols.hpp"

/*
struct POINT {
	int x;
	int y;
};

bool IsPointInFrame(POINT pos) {
	return (pos.x > 0 && pos.x < console.width-1 && pos.y > 0 && pos.y < console.height-1);
}
*/

Figure::Figure() {
	memset(this, 0, sizeof(*this));
}

void Figure::SetShape(const char* shapeSymbols) {
	for(int i=0; i < SHAPE_HEIGHT; i++)
		for(int j=0; j < SHAPE_WIDTH; j++)
			shape[i][j] = shapeSymbols[i*SHAPE_WIDTH+j];
}

void Figure::CalcCoord() {
	int coordX;
	int coordY;
	coordsNumber = 0;
	for(int i = 0; i < SHAPE_WIDTH; i++)
		for(int j = 0; j < SHAPE_HEIGHT; j++)
			if(shape[j][i] == SYMBOL_SHAPE) {
				if(turn == 0) {
					coordX = x+i;
					coordY = y+j;
				}
				else if(turn == 1) {
					coordX = x+(SHAPE_HEIGHT-j-1);
					coordY = y+i;
				}
				else if(turn == 2) {
					coordX = x+(SHAPE_WIDTH-i-1);
					coordY = y+(SHAPE_HEIGHT-j-1);
				}
				else if(turn == 3) {
					coordX = x+j;
					coordY = y+(SHAPE_HEIGHT-i-1);
				}

				coords[coordsNumber] = (COORD){coordX, coordY};
				coordsNumber++;
			}
}

//enum CheckBordersReturn {noCollision, bordersCollision, bottomCollision};
int Figure::CheckBorders() {
	CalcCoord();
	
	for(int i = 0; i < coordsNumber; i++)
		if(coords[i].x < 0 || coords[i].x > FIELD_WIDTH-2)
			return bordersCollision;
	
	for(int i = 0; i < coordsNumber; i++)
		if(coords[i].y >= FIELD_HEIGHT-2 || field->fld[coords[i].y][coords[i].x] == SYMBOL_FIGURE_DOWN)
			return bottomCollision;
	
	return noCollision;
}

int Figure::GetTurn() {
	return turn;
}

void Figure::SetTurn(int _turn) {
	int turnPrev = turn;
	turn = _turn > 3 ? 0 : (_turn < 0 ? 3 : _turn);

	int check = CheckBorders();
	if(check == noCollision)
		return;
	
	if(check == bordersCollision) {
		int coordX = x;
		int k = (x > (FIELD_WIDTH/2) ? -1 : 1);

		for(int i = 1; i < 3; i++) {
			x += k;
			if(CheckBorders() == noCollision)
				return;
		}

		x = coordX;
	}
	
	turn = turnPrev;
	CalcCoord();
}

void Figure::SetPos(int _y, int _x) {
	x = _x;
	y = _y;
	CalcCoord();
}

void Figure::PutToScreen(ScreenMap &scr) {
	for(int i = 0; i < coordsNumber; i++) {
		scr[coords[i].y][coords[i].x*2] = SYMBOL_FIGURE;
		scr[coords[i].y][coords[i].x*2+1] = SYMBOL_FIGURE;
	}
}

void Figure::PutToField(FieldMap &fld) {
	for(int i = 0; i < coordsNumber; i++)
		fld[coords[i].y][coords[i].x] = SYMBOL_FIGURE_DOWN;
}

void Figure::SetField(Field* _field) {
	field = _field;
}

bool Figure::Move(int dy, int dx) {
	int xPrev = x;
	int yPrev = y;
	SetPos(y + dy, x + dx);

	int check = CheckBorders();
	if(check != noCollision) {
		SetPos(yPrev, xPrev);
		if(check == bottomCollision)
			return false;
	}

	return true;
}

