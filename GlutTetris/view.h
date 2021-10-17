#pragma once
#include "global_consts.h"
#include "tetromino.h"
#include "field.h"



void DrawField(Field const& f);
void DrawTetramino(Tetramino const& obj);
void ConsoleScorePrint(int score, int speed);
