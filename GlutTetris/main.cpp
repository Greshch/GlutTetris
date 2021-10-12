#include <stdio.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "view.h"
#include "snake.h"

int pause = 50;


void Renderer();
void Tick();




int main(int argc, char** argv)
{
	snake[0] = { 10, 8 };
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(320, 26);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Snake");
	glClearColor(1.0, 1.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COL, ROW, 0.0, -1.0, 1.0);

	glutDisplayFunc(Renderer);
	glutMainLoop();
	return 0;
}

void Renderer()
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawField();
	DrawSnake();
	glutSwapBuffers();
}

void Tick()
{
}
