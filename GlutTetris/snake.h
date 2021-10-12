#pragma once

struct Point
{
	int x;
	int y;
};

int const SNAKE_MAX_SIZE = 100;
extern Point snake[SNAKE_MAX_SIZE];
extern int snake_last;

void DrawSnake();
void UpdateSnake();
