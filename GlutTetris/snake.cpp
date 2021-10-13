#include <GL/freeglut.h>
#include "snake.h"
#include "global_consts.h"

Point snake[SNAKE_MAX_SIZE]
{ 
	{10, 12},
	{10, 13},
	{10, 14}
};

int snake_last = 2;
DIRECTION snake_dir = UP;


void UpdateSnake()
{
	//Design draw (0,0)
	if (snake_last < SNAKE_MAX_SIZE - 1)
	{
		snake[snake_last + 1].x = -1;
		snake[snake_last + 1].y = -1;
	}
	
	
	for (int i = snake_last; i > 0; --i)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (snake_dir == DOWN)	snake[0].y += 1;
	if (snake_dir == LEFT)	snake[0].x -= 1;
	if (snake_dir == RIGHT)	snake[0].x += 1;
	if (snake_dir == UP)		snake[0].y -= 1;
}

bool HasSnakeItselfCollision()
{
	for (size_t i = 3; i <= snake_last; i++)
	{
		if (snake[0].x == snake[i].x &&
			snake[0].y == snake[i].y)
		{
			return true;
		}
	}
	return false;
}
