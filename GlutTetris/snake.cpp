#include <GL/freeglut.h>
#include "snake.h"
#include "global_consts.h"

Point snake[SNAKE_MAX_SIZE]
{ 
	{10, 8},
	{10, 9},
	{10, 10}
};

int snake_last = 2;
DIRECTION dir = UP;

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
	if (dir == DOWN)	snake[0].y += 1;
	if (dir == LEFT)	snake[0].x -= 1;
	if (dir == RIGHT)	snake[0].x += 1;
	if (dir == UP)		snake[0].y -= 1;
}
