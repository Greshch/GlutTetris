#include <GL/freeglut.h>
#include <string>
#include "view.h"
#include "global_consts.h"
#include "snake.h"
#include "food.h"

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

void DrawFood()
{
	glColor3f(1.0, 0.5, 0.5);
	glRectf(food.x, food.y, food.x + 1, food.y + 1);
}

void DebugPrintSnake(int dir, int dx, int dy)
{
	using std::string;
	string sdir;
	if (dir == 102)	sdir = "left";
	else if (dir == 100)	sdir = "right";
	else if (dir == 101)	sdir = "up";
	else if (dir == 103)	sdir = "down";
	
	printf("dir = %s\tdx = %d\tdy = %d\n", sdir.c_str(), dx, dy);
	
}
