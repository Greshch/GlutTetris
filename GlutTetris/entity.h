#pragma once
#include "screen.h"

enum TETRAMINO {
	LENGTH = 4,
	SZ = 7
};

enum COLORS {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	BLACK,
	WHITE,
	END
};

struct Point {
	int x;
	int y;
};

void TranslateFromPaternsToTetramino(Point* pPoint, int id);
void UpdateTetramino(Point *curent, int dx, int dy);

extern int const PATERNS[TETRAMINO::SZ][TETRAMINO::LENGTH];
