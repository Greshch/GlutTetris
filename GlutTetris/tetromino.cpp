#include "tetromino.h"
#include "global_consts.h"

void SetTetramino(Tetramino& obj, int id, int left, int up)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		obj[i].x = tetraminos[id][i] % 2 + left;
		obj[i].y = tetraminos[id][i] / 2 + up;
	}
}
