#include "tetromino.h"
#include "global_consts.h"

Tetramino t_buffer;

void SetTetramino(Tetramino& obj, int id, int left, int up)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		obj[i].x = tetraminos[id][i] % 2 + left;
		obj[i].y = tetraminos[id][i] / 2 + up;
	}
}

void RotateTetramino(Tetramino& obj)
{
	int Xo = obj[1].x;
	int Yo = obj[1].y;
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		int x = obj[i].x - Xo;;
		int y = obj[i].y - Yo;
		obj[i].x = Xo - y;
		obj[i].y = Yo + x;
	}
}

void WriteToBuffer(Tetramino const& src)
{
	CopyTetramino(t_buffer, src);
}

void ReadFromBuffer(Tetramino& dest)
{
	CopyTetramino(dest, t_buffer);
}

Tetramino& GetBuffer()
{
	return t_buffer;
}


void CopyTetramino(Tetramino& dest, Tetramino const& src)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
	}
}

bool HasCollisionWithField(Tetramino const& obj)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		int x = obj[i].x;
		int y = obj[i].y;
		if (x < FIELD_LEFT || x >= FIELD_RIGHT)
		{
			return true;
		}

		if (y < FIELD_UP || y >= FIELD_DOWN)
		{
			return true;
		}
	}
	return false;
}
