#pragma once
#include "global_consts.h"

struct Point
{
	int x;
	int y;
};

int const TETRAMINO_SZ = 4;
int const TETRAMINO_CNT = 7;

typedef Point Tetramino[TETRAMINO_SZ];

int const const tetraminos[TETRAMINO_CNT][TETRAMINO_SZ]
{
	{2, 4, 5, 6}, //T
	{2, 4, 5, 7}, //S
	{3, 5, 4, 6}, //Z
	{2, 3, 5, 4}, //O
	{1, 3, 5, 7}, //I
	{3, 5, 7, 6}, //J
	{2, 4, 6, 7}  //L
};

void SetTetramino(Tetramino& obj, int id, int left = COL / 2, int up = FIELD_UP);


