#include "field.h"
#include "global_consts.h"
#include "tetromino.h"

void MergeTetramino(Field& field,Tetramino const& tetramino)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		int x = tetramino[i].x;
		int y = tetramino[i].y;
		field[y][x] = 1;
	}
}

bool IsThisLineFill(Field const& field, int line)
{
	for (size_t i = FIELD_LEFT; i < FIELD_RIGHT; i++)
	{
		if (field[line][i] == 0)	return false;
	}
	return true;
}

bool ErasedLineFill(Field& field)
{
	bool res = false;
	for (size_t line = FIELD_DOWN - 1; line > FIELD_UP; --line)
	{
		if (IsThisLineFill(field, line))
		{
			EraseLineField(field, line);
			res = true;
		}
	}
	return res;
}

bool IsThisLineEmpty(Field const& field, int line)
{
	for (size_t i = FIELD_LEFT; i < FIELD_RIGHT; i++)
	{
		if (field[line][i])	return false;
	}
	return true;
}

void CopyLineFromTo(Field& field, int dest, int src)
{
	for (size_t i = FIELD_LEFT; i < FIELD_RIGHT; i++)
	{
		field[dest][i] = field[src][i];
	}
}

void EraseLineField(Field& field, int line)
{
	for (size_t i = FIELD_LEFT; i < FIELD_RIGHT; i++)
	{
		field[line][i] = 0;
	}
}


