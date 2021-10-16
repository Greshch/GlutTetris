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
