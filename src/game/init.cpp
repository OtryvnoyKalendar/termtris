#include "init.hpp"
#include "curscore.hpp"
//#include "conscore.hpp"
#include "sigcore.hpp"
#include "screen.hpp"
#include "shape.hpp"
#include "figure.hpp"
#include "field.hpp"

Console console = {"Tetrix"};
Screen screen;
Figure figure;
Field field;

//const int shapeArrayNumber = 5;
char* shapeArray[SHAPE_ARRAY_NUMBER] = {
	(char*)".....**..**.....",
	(char*)"....****........",
	(char*)"....***..*......",
	(char*)".....***.*......",
	(char*)".....**.**......",
};

void BeforeCloseProgram() {
	CloseNcursesMode();
}

void InitConsole() {
	SetSignals();
	SetConsoleSize(console.width, console.height);
	SetConsoleTitle(console.title);
	OpenNcursesMode();
}

void InitAll() {
	InitConsole();

	figure.SetField(&field);
	figure.SetShape("....***.*.......");
	figure.SetPos(0, FIELD_WIDTH/2 - SHAPE_WIDTH/2);
}

