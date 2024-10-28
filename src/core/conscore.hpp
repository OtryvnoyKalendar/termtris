#pragma once

void SetConsoleSize(int consoleWidth, int consoleHeight);
void SetConsoleTitle(const char *consoleTitle);

const int FIELD_WIDTH = 20;
const int FIELD_HEIGHT = 30;

const int SCREEN_WIDTH = FIELD_WIDTH * 2;
const int SCREEN_HEIGHT = FIELD_HEIGHT;

struct Console {
	static const int width = SCREEN_WIDTH;
	static const int height = SCREEN_HEIGHT;
	const char* title;
};

extern Console console;

