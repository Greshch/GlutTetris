#pragma once
#include "global_consts.h"

struct Point
{
	int x;
	int y;
};

int const SNAKE_MAX_SIZE = 100;
extern Point snake[SNAKE_MAX_SIZE];
extern int snake_last;
extern DIRECTION dir;

void DrawSnake();
void UpdateSnake();
bool HasSnakeItselfCollision(int& new_size);
