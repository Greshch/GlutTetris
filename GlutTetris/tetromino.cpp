#include <GL/freeglut.h>
#include "tetromino.h"
#include "global_consts.h"
#include "field.h"

Tetramino t_buffer;
int dx = 0;
int dy = 1;

void SetTetramino(Tetramino& obj, int id, int left, int up)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		obj[i].x = tetraminos[id][i] % 2 + left;
		obj[i].y = tetraminos[id][i] / 2 + up;
	}
}

void NewTetramino(Tetramino& obj)
{
	int rndm_id = rand() % TETRAMINO_CNT;
	SetTetramino(obj, rndm_id);
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

void UpdateTetramino(Tetramino& obj)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		obj[i].x += dx;
		obj[i].y += dy;
	}
}

void ReadFromBuffer(Tetramino& dest)
{
	CopyTetramino(dest, t_buffer);
}

void KeyEvent(int key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		dx = -1;
		break;
	
	case GLUT_KEY_RIGHT:
		dx = 1;
		break;

	default:
		break;
	}
}

Tetramino& GetBuffer()
{
	return t_buffer;
}

void ResetKey()
{
	dx = 0;
}


void CopyTetramino(Tetramino& dest, Tetramino const& src)
{
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
	}
}

bool HasCollisionWithField(Tetramino const& obj, Field const& field)
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
