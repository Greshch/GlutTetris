#include <GL/freeglut.h>
#include "view.h"
#include "global_consts.h"
#include "snake.h"

void DrawField()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (size_t y = RANGE_UP; y <= RANGE_DOWN; y++)
	{
		glVertex2f(RANGE_LEFT, y);
		glVertex2f(RANGE_RIGHT, y);
	}
	
	for (size_t x = RANGE_LEFT; x <= RANGE_RIGHT; x++)
	{
		glVertex2f(x, RANGE_UP);
		glVertex2f(x, RANGE_DOWN);
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
