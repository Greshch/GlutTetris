#include <GL/freeglut.h>
#include <stdio.h>
#include "view.h"
#include "global_consts.h"
#include "tetromino.h"

void DrawField(Field const& field)
{
	glColor3f(0.0, 0.0, 1.0);
	// --- Draw Frame ---
	glBegin(GL_LINES);
	for (size_t y = FIELD_UP; y <= FIELD_DOWN; y++)
	{
		glVertex2f(FIELD_LEFT, y);
		glVertex2f(FIELD_RIGHT, y);
	}

	for (size_t x = FIELD_LEFT; x <= FIELD_RIGHT; x++)
	{
		glVertex2f(x, FIELD_UP);
		glVertex2f(x, FIELD_DOWN);
	}
	glEnd();
	// --- End Frame ---

	// -- Draw rest inner part
	for (size_t y = FIELD_UP; y < FIELD_DOWN; y++)
	{
		for (size_t x = FIELD_LEFT; x < FIELD_RIGHT; x++)
		{
			if (field[y][x] == 1)
			{
				glColor3f(1, 0, 0);
				glRectf(x, y, x + 1, y + 1);
			}
		}
	}
}

void DrawTetramino(Tetramino const& obj)
{
	glColor3f(0.0, 1.0, 0.0);
	for (size_t i = 0; i < TETRAMINO_SZ; i++)
	{
		glRectf(obj[i].x, obj[i].y, obj[i].x + 1, obj[i].y + 1);
	}
}

void ConsoleScorePrint(int score, int speed)
{
	system("cls");
	printf("-------------------\n");
	printf("score: %d\n", score);
	printf("speed: %d\n", speed);
	printf("-------------------\n");
}


