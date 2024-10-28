#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "closecore.hpp"
#include "colors.hpp"
#include "graphic.hpp"
#include "sigcore.hpp"
#include "draw.hpp"
#include "figure.hpp"
#include "field.hpp"

#define KEY_ESCAPE ((char)27)

void GetInput() {
	CheckSignals();
	
	static int turnTime = 0;
	const int turnTimer = 20;

	char input = getch();
	switch(input) {
		case KEY_ESCAPE:
			CloseProgram();
		case 'a':
			figure.Move(0, -1); break;
		case 's':
			figure.Move(1, 0); break;
		case 'd':
			figure.Move(0, 1); break;
		case 'w':
			if(turnTime >= turnTimer) {
				figure.SetTurn(figure.GetTurn() + 1);
				turnTime = 0;
			}
			break;
	};

	if(turnTime < turnTimer)
		turnTime += 1;
}

void MoveFigureDown() {
	static int tick = 0;
	srand(time(NULL));
	tick++;
	
	if(tick >= 2000) {
		if(!figure.Move(1, 0)) {
			figure.PutToField(field.fld);
			figure.SetShape(shapeArray[rand() % SHAPE_ARRAY_NUMBER]);
			figure.SetPos(0, FIELD_WIDTH/2 - SHAPE_WIDTH/2);
			if(figure.CheckBorders() != noCollision)
				field.Clear();
		}
		tick = 0;
	}

	field.Burning();
}

void GameLogic() {
	MoveFigureDown();
	GetInput();
	ShowGraphic();
	refresh();
}

