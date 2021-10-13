#include <GL/freeglut.h>
#include <stdio.h>
#include "snake.h"
#include "global_consts.h"
#include "view.h"

Point snake[SNAKE_MAX_SIZE]
{ 
	{10, 12},
	{10, 13},
	{10, 14}
};

int snake_last = 2;
int snake_dir = GLUT_KEY_UP;
bool is_update = true;
int dx = 0;
int dy = 0;


void UpdateSnake()
{
	//Design draw (0,0)
	if (snake_last < SNAKE_MAX_SIZE - 1)
	{
		snake[snake_last + 1].x = -1;
		snake[snake_last + 1].y = -1;
	}
	
	// go from tail to head
	for (int i = snake_last; i > 0; --i)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}

	if (snake_dir == GLUT_KEY_DOWN)
	{
		dy = 1;
		dx = 0;
	}
	else if (snake_dir == GLUT_KEY_LEFT)
	{
		dx = -1;
		dy = 0;
	}
	else if (snake_dir == GLUT_KEY_RIGHT)
	{
		dx = 1;
		dy = 0;
	}
	else if (snake_dir == GLUT_KEY_UP)
	{
		dy = -1;
		dx = 0;
	}

	snake[0].x += dx;
	snake[0].y += dy;
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

bool IsValidDir(int dir)
{
	static int old_dir = dir;
	//DebugPrintSnake(dir, old_dir, dx, dy);

	if (
		dir == GLUT_KEY_DOWN && dy == -1
		||
		dir == GLUT_KEY_LEFT && dx == 1
		||
		dir == GLUT_KEY_UP && dy == 1
		||
		dir == GLUT_KEY_RIGHT && dx == -1
		
		)
	{
		return false;
	}
	
	if (snake_dir == GLUT_KEY_DOWN && dir == GLUT_KEY_UP) return false;
	if (snake_dir == GLUT_KEY_LEFT && dir == GLUT_KEY_RIGHT) return false;
	if (snake_dir == GLUT_KEY_UP && dir == GLUT_KEY_DOWN) return false;
	if (snake_dir == GLUT_KEY_RIGHT && dir == GLUT_KEY_LEFT) return false;

	old_dir = dir;
	return true;
}

bool HasSnakeBorderCollision()
{
	if (snake_dir == GLUT_KEY_LEFT && snake[0].x == RANGE_LEFT)
	{
		return true;
	}
	else if (snake_dir == GLUT_KEY_UP && snake[0].y == RANGE_UP)
	{
		return true;
	}
	else if (snake_dir == GLUT_KEY_RIGHT && snake[0].x == RANGE_RIGHT - 1)
	{
		return true;
	}
	else if (snake_dir == GLUT_KEY_DOWN && snake[0].y == RANGE_DOWN - 1)
	{
		return true;
	}
	return false;
}
