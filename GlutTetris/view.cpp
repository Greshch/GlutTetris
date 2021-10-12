#include <GL/freeglut.h>
#include "view.h"
#include "global_consts.h"
#include "snake.h"

void DrawField()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (size_t y = 1; y < ROW; y++)
	{
		glVertex2f(1.0, y);
		glVertex2f(COL - 1, y);
	}
	
	for (size_t x = 1; x < COL; x++)
	{
		glVertex2f(x, 1);
		glVertex2f(x, ROW - 1);
	}
	glEnd();
}

void DrawSnake()
{
	glColor3f(0.0, 1.0, 0.0);
	for (size_t i = 0; i <= snake_last; i++)
	{
		glRectf(snake[i].x, snake[i].y, snake[i].x + 1, snake[i].y + 1);
	}

}
