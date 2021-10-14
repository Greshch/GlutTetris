#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "tetromino.h"
#include "view.h"


int pause = 360;
int score = 0;
int speed = 10;



void Renderer();


void Tick();
void Timer(int);
void Keyboard(int key, int, int);



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(600, 32);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Tetris Game");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COL, ROW, 0.0, -1.0, 1.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glutDisplayFunc(Renderer);
	glutTimerFunc(pause, Timer, 0);
	glutSpecialFunc(Keyboard);
	glutMainLoop();
	return 0;
}

void Renderer()
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	glutSwapBuffers();
}



void Tick()
{
	
}

void Timer(int = 0)
{
	Renderer();
	Tick();
	glutTimerFunc(pause, Timer, 0);
}

void Keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_F11:
		printf("F11 pause\n");
		break;

	case GLUT_KEY_F12:
		printf("F12 exit\n");
		exit(0);
		break;

	case GLUT_KEY_LEFT:
		printf("LEFT\n");
		break;
	
	case GLUT_KEY_UP:
		printf("UP\n");
		break;

	case GLUT_KEY_RIGHT:
		printf("RIGHT\n");
		break;

	case GLUT_KEY_DOWN:
		printf("DOWN\n");
		break;

	default:
		break;
	}
}
