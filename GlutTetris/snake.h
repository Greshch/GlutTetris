#pragma once
#include "global_consts.h"

struct Point
{
	int x;
	int y;
};

int const SNAKE_MAX_SIZE = ROW * COL;
extern Point snake[SNAKE_MAX_SIZE];
extern int snake_last;
extern int snake_dir;
extern bool is_update;
extern int dx;
extern int dy;

void DrawSnake();
void UpdateSnake();
bool HasSnakeItselfCollision();
bool HasSnakeBorderCollision();
bool IsValidDir(int dir);
