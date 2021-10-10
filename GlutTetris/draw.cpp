#include <GL/freeglut.h>
#include "draw.h"
#include "screen.h"

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
