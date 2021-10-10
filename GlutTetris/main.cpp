#include <GL/freeglut.h>
#include <stdlib.h>
#include "screen.h"

void DisplayFuncCallback();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(640, 16);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Tetris");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0);
	glutDisplayFunc(DisplayFuncCallback);
	glutMainLoop();
	return 0;
}

void DisplayFuncCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
