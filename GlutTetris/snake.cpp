#include <GL/freeglut.h>
#include "snake.h"
#include "global_consts.h"

Point snake[SNAKE_MAX_SIZE]{ {0, 0} };

int snake_last = 0;

void DrawSnake()
{
	glColor3f(0.0, 1.0, 0.0);
	for (size_t i = 0; i <= snake_last; i++)
	{
		glRectf(snake[i].x, snake[i].y, snake[i].x + 1, snake[i].y + 1);
	}

}

void UpdateSnake()
{
	for (int i = snake_last; i > 0; --i)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
}