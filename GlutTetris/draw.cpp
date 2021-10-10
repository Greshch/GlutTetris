#include <GL/freeglut.h>
#include <stdio.h>
#include "draw.h"
#include "screen.h"
#include "entity.h"

void DrawTails()
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	for (size_t i = 0; i <= M; i++)
	{
		glVertex2f(0.0, i * SCALE);
		glVertex2f(N * SCALE, i * SCALE);
	}
	
	for (size_t j = 0; j <= N; j++)
	{
		glVertex2f(j * SCALE, 0.0);
		glVertex2f(j * SCALE, M * SCALE);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
}

void DrawTetramino(Point* pPoint, COLORS color)
{
	double r = 0, g = 0, b = 0;
	switch (color)
	{
	case RED:
		r = 1.0;
		break;

	case ORANGE:
		r = 1.0;
		g = 0.5;
		break;

	case YELLOW:
		r = 1.0;
		g = 1.0;
		break;

	case GREEN:
		g = 1.0;
		break;

	case BLUE:
		b = 1.0;
		break;

	case VIOLET:
		r = 0.5;
		g = 0.5;
		b = 0.5;
		break;

	case WHITE:
		r = 1.0;
		g = 1.0;
		b = 1.0;
		break;

	default:
		break;
	}
	glColor3f(r, g, b);
	for (size_t i = 0; i < TETRAMINO::LENGTH; i++)
	{
		glRectf(pPoint[i].x * SCALE, pPoint[i].y * SCALE, 
			(pPoint[i].x + 1) * SCALE, (pPoint[i].y + 1) * SCALE);
	}
}

void PrintTetramino(Point* pPoint)
{
	for (size_t i = 0; i < TETRAMINO::LENGTH; i++)
	{
		printf("{%2d,%2d}\t", pPoint[i].x, pPoint[i].y);
	}
	printf("\n");
}
