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
extern Tetramino t_buffer;

int const const tetraminos[TETRAMINO_CNT][TETRAMINO_SZ]
{
	{0, 2, 3, 4}, //T
	{0, 2, 3, 5}, //S
	{1, 3, 2, 4}, //Z
	{0, 1, 3, 2}, //O
	{1, 3, 5, 7}, //I
	{1, 3, 5, 4}, //J
	{0, 2, 4, 5}  //L
};

enum NAMES
{
	TE,	//T
	SI,	//S
	ZET,//Z
	OU,	//O
	IS,	//I
	JE,	//J
	LE	//L
};

void SetTetramino(Tetramino& obj, int id, int left = COL / 2 - 1, int up = FIELD_UP);
void RotateTetramino(Tetramino& obj);
void WriteToBuffer(Tetramino const& src);
void ReadFromBuffer(Tetramino& dest);
Tetramino& GetBuffer();
static void CopyTetramino(Tetramino& dest, Tetramino const& src);
bool HasCollisionWithField(Tetramino const& obj);


