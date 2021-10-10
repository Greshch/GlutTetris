#include "entity.h"
#include "screen.h"

int const PATERNS[TETRAMINO::SZ][TETRAMINO::LENGTH]
{
	{1, 3, 5, 7}, //I
	{3, 5, 7, 6}, //J
	{2, 4, 6, 7}, //L
	{2, 3, 5, 4}, //O
	{3, 5, 4, 7}, //T
	{2, 4, 5, 7}, //S
	{3, 5, 4, 6}, //Z
};

void TranslateFromPaternsToTetramino(Point* pPoint, int id)
{
	for (size_t i = 0; i < TETRAMINO::LENGTH; i++)
	{
		pPoint[i].x = PATERNS[id][i] % 2 + N / 2 - 1;
		pPoint[i].y = PATERNS[id][i] / 2;
	}
}

void UpdateTetramino(Point* curent, int dx, int dy)
{
	for (size_t i = 0; i < TETRAMINO::LENGTH; i++)
	{
		curent[i].x += dx;
		curent[i].y += dy;
	}
}
