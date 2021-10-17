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

bool UpdateField(Field& field)
{
	bool res = false;
	for (size_t line = FIELD_UP; line < FIELD_DOWN;)
	{
		if (IsThisLineFill(field, line))
		{

		}
		else
		{

		}

	}
	return res;
}

void EraseLineField(Field& field, int line)
{
	for (size_t i = FIELD_LEFT; i < FIELD_RIGHT; i++)
	{
		field[line][i] = 0;
	}
}
