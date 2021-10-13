#pragma once
#include "snake.h"
#include "global_consts.h"

extern Point food;

void FoodNew(Point obj[], int const obj_size);
bool FoodCollisionWithSnake(Point obj[], int const obj_size);
