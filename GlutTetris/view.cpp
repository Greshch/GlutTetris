#include <GL/freeglut.h>
#include "view.h"
#include "global_consts.h"

void DrawField()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (size_t y = FIELD_UP; y <= FIELD_DOWN; y++)
	{
		glVertex2f(FIELD_LEFT, y);
		glVertex2f(FIELD_RIGHT, y);
	}

	for (size_t x = FIELD_LEFT; x <= FIELD_RIGHT; x++)
	{
		glVertex2f(x, FIELD_UP);
		glVertex2f(x, FIELD_DOWN);
	}
	glEnd();
}
