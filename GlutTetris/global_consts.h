#pragma once

int const ROW = 20;
int const COL = 30;

int const SCALE = 34;

int const WIDTH = COL * SCALE;
int const HEIGHT = ROW * SCALE;

int const RANGE_UP = 1;
int const RANGE_DOWN = ROW - 1;
int const RANGE_LEFT = 1;
int const RANGE_RIGHT = COL - 1;

enum DIRECTION
{
	DOWN, LEFT, RIGHT, UP
};
