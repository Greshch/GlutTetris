#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "view.h"
#include "snake.h"
#include "food.h"

int pause = 350;


void Renderer();
void Tick();
void Timer(int);
void Keyboard(int key, int, int);



int main(int argc, char** argv)
{
	srand(time(0));
	FoodNew(snake, snake_last + 1);
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
	glutTimerFunc(pause, Timer, 0);
	glutSpecialFunc(Keyboard);
	glutMainLoop();
	return 0;
}

void Renderer()
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawField();
	DrawSnake();
	DrawFood();
	glutSwapBuffers();
}

void Tick()
{
	UpdateSnake();
	if (FoodCollisionWithSnake(snake, 1))
	{
		//printf("##x=%3d\ty=%3d\n", food.x, food.y);
		FoodNew(snake, snake_last + 1);
	}
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
	case GLUT_KEY_LEFT:		dir = LEFT;		break;

	case GLUT_KEY_UP:		dir = UP;		break;

	case GLUT_KEY_RIGHT:	dir = RIGHT;	break;

	case GLUT_KEY_DOWN:		dir = DOWN;		break;

	default:	break;
	}
}
