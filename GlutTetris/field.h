#pragma once
#include "global_consts.h"
#include "tetromino.h"


typedef int Field[ROW][COL];

void MergeTetramino(Field& field, Tetramino const& tetramino);
bool IsThisLineFill(Field const& field, int line);
bool ErasedLineFill(Field& field);
bool IsThisLineEmpty(Field const& field, int line);
void CopyLineFromTo(Field& field, int dest, int src);
void EraseLineField(Field& field, int line);