#include <random>
#include <stdio.h>
#include "food.h"
#include "snake.h"
#include "global_consts.h"

Point food{};

void FoodNew(Point obj[], int const obj_size)
{
	while (true)
	{
		int x = rand() % (RANGE_RIGHT - RANGE_LEFT) + 1;
		int y = rand() % (RANGE_DOWN - RANGE_UP) + 1;
		//printf("x=%3d\ty=%3d\n", x, y);
		food.x = x;
		food.y = y;
		if (!FoodCollisionWithSnake(obj, obj_size))
		{
			break;
		}
	}
}

bool FoodCollisionWithSnake(Point obj[], int const obj_size)
{
	int x = food.x;
	int y = food.y;
	for (size_t i = 0; i < obj_size; i++)
	{
		if (obj[i].x == x && obj[i].y == y)
		{
			return true;
		}
	}
	return false;
}
