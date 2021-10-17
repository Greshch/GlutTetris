#pragma once
#include "global_consts.h"
#include "tetromino.h"


typedef int Field[ROW][COL];

void MergeTetramino(Field& field, Tetramino const& tetramino);
bool IsThisLineFill(Field const& field, int line);
bool UpdateField(Field& field);
void EraseLineField(Field& field, int line);