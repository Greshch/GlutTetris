#include <GL/freeglut.h>
#include <stdio.h>
#include "screen.h"
#include "draw.h"
#include "entity.h"

Point curent[TETRAMINO::LENGTH] { {0, 0} };
int dx = 0;
int dy = 0;
unsigned pause = 360;


void DisplayFuncCallback();
void TimerFuncCallback(int);
void SpecialFunc(int key, int, int);

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
	glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
	glutDisplayFunc(DisplayFuncCallback);
	glutTimerFunc(pause, TimerFuncCallback, 0);
	glutSpecialFunc(SpecialFunc);
	glutMainLoop();
	return 0;
}

void DisplayFuncCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTails();
	if (curent[1].y)
		DrawTetramino(curent, COLORS::GREEN);
	glutSwapBuffers();
}

void TimerFuncCallback(int)
{
	glutPostRedisplay();
	if (curent[1].y == 0)
	{
		TranslateFromPaternsToTetramino(curent, 1);
	}
	else
	{
		UpdateTetramino(curent, dx, dy);
		dx = 0;
	}
	glutTimerFunc(pause, TimerFuncCallback, 0);
}

void SpecialFunc(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		dx = -1;
		break;

	case GLUT_KEY_RIGHT:
		dx = 1;
		break;

	default:
		break;
	}
}
