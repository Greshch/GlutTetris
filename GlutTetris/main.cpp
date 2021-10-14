#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "tetromino.h"
#include "view.h"

int pause = 360;
int score = 0;
int speed = 10;
Tetramino tetramino;
int num = 0;
bool is_rotate_tetramino = false;
bool is_set_tetramino = false;
bool is_move_tetramino = false;



void Renderer();


void Tick();
void Timer(int);
void Keyboard(int key, int, int);



int main(int argc, char** argv)
{
	srand(time(0));
	SetTetramino(tetramino, num);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(600, 32);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Tetris Game");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COL, ROW, 0.0, -1.0, 1.0);
	glClearColor(1.0, 1.0, 0.0, 1.0);

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
	DrawTetramino(tetramino);
	
	glutSwapBuffers();
}



void Tick()
{
	if (is_set_tetramino)
	{
		num++;
		num = num % TETRAMINO_CNT;
		SetTetramino(tetramino, num);
		is_set_tetramino = false;
	}

	if (is_move_tetramino)
	{
		is_move_tetramino = false;
		WriteToBuffer(tetramino);
		UpdateTetramino(GetBuffer());
		if (HasCollisionWithField(GetBuffer()))
		{
			printf("#COLLISION\n");
			return;
		}
		UpdateTetramino(tetramino);
		ResetKey();
	}
	
	if (is_rotate_tetramino)
	{
		is_rotate_tetramino = false;
		WriteToBuffer(tetramino);
		RotateTetramino(GetBuffer());
		if (HasCollisionWithField(GetBuffer()))
		{
			printf("#COLLISION\n");
			return;
		}
		RotateTetramino(tetramino);
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
	case GLUT_KEY_F11:
		//printf("F11 pause\n");
		break;

	case GLUT_KEY_F12:
		//printf("F12 exit\n");
		exit(0);
		break;

	case GLUT_KEY_LEFT:
		//printf("LEFT\n");
		is_move_tetramino = true;
		KeyEvent(GLUT_KEY_LEFT);
		break;
	
	case GLUT_KEY_UP:
		is_rotate_tetramino = true;
		//printf("UP\n");
		break;

	case GLUT_KEY_RIGHT:
		//printf("RIGHT\n");
		is_move_tetramino = true;
		KeyEvent(GLUT_KEY_RIGHT);
		break;

	case GLUT_KEY_DOWN:
		//is_set_tetramino = true;
		//printf("DOWN\n");
		break;

	default:
		break;
	}
}
