#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "view.h"
#include "snake.h"
#include "food.h"

int pause = 600;



void Renderer();
//void RendererEnd();

//int id_render = 0;
//void(*renderers[2])()
//{
//	Renderer,
//	RendererEnd
//};

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

//void RendererEnd()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glutSwapBuffers();
//}

void Tick()
{
	if (!is_update)
	{
		return;
	}
	UpdateSnake();
	if (FoodCollisionWithSnake(snake, 1))
	{
		FoodNew(snake, snake_last + 1);
		++snake_last;
	}
	
	if (HasSnakeItselfCollision() || HasSnakeBorderCollision())
	{
		is_update = false;
		glutDestroyWindow(glutGetWindow());
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
	if (!IsValidDir(key))
	{
		//printf("..Wrong direction!!..\n");
		return;
	}
	switch (key)
	{
	case GLUT_KEY_LEFT:	
		snake_dir = GLUT_KEY_LEFT;		
		break;
							
	case GLUT_KEY_UP:		
		snake_dir = GLUT_KEY_UP;		
		break;
							
	case GLUT_KEY_RIGHT:	
		snake_dir = GLUT_KEY_RIGHT;	
		break;
							
	case GLUT_KEY_DOWN:		
		snake_dir = GLUT_KEY_DOWN;		
		break;

	case GLUT_KEY_F11:
		is_update = (!is_update);
		break;

	case GLUT_KEY_F12:
		glutDestroyWindow(glutGetWindow());
		break;

	default:	break;
	}
}
