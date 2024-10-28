#pragma once

#include "shape.hpp"
#include "screen.hpp"
#include "field.hpp"

enum CheckBordersReturn {noCollision, bordersCollision, bottomCollision};

class Figure {
	int x, y;
	Shape shape;
	COORD coords[SHAPE_HEIGHT*SHAPE_WIDTH];
	int turn;
	int coordsNumber;
	Field* field;
public:
	Figure();
	int GetTurn();
	void SetTurn(int _turn);
	void SetField(Field* _field);
	void SetShape(const char* shapeSymbols);
	void SetPos(int _y, int _x);
	void PutToScreen(ScreenMap &scr);
	void PutToField(FieldMap &fld);
	bool Move(int dy, int dx);
	int CheckBorders();
private:
	void CalcCoord();
};

extern Figure figure;

