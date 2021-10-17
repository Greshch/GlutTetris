#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>
#include "global_consts.h"
#include "tetromino.h"
#include "view.h"
#include "field.h"

int pause = 720;
int score = 0;
int speed = 10;
Tetramino tetramino;
Field field{ 0 };
bool is_rotate_tetramino = false;
bool is_down_key_pressed = false;
bool is_over = false;
bool is_pause = false;

void Renderer();
void Tick();
void Timer(int);
void Keyboard(int key, int, int);



int main(int argc, char** argv)
{
	srand(time(0));
	NewTetramino(tetramino);

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

	DrawField(field);
	DrawTetramino(tetramino);
	
	glutSwapBuffers();
}



void Tick()
{
	if (is_pause)
	{
		return;
	}
	//Check exit:
	if (is_over)
	{
		exit(0);
	}
	//-----------Move Begin
	WriteToBuffer(tetramino);
	UpdateTetramino(GetBuffer());
	// Check colision with left or right side mainly
	if (HasCollisionWithField(GetBuffer(), field))
	{
		// Skip key pressed
		ResetKey();
	}
		
	WriteToBuffer(tetramino);
	UpdateTetramino(GetBuffer());
	// Has achived DOWN or last Line
	if (!HasCollisionWithField(GetBuffer(), field))
	{	
		UpdateTetramino(tetramino);
	}
	else
	{
		//printf("ACHIVE DOWN Lets create new tetramino\n");
		is_down_key_pressed = false;
		MergeTetramino(field, tetramino);
		NewTetramino(tetramino);

		/*system("cls");
		for (size_t i = FIELD_UP; i < FIELD_DOWN; i++)
		{
			printf("%d line is field - > %d\n", i, IsThisLineFill(field, i));
		}*/
		if (ErasedLineFill(field))
		{
			UpdateField(field);
		}

		if (HasCollisionWithField(tetramino, field) && tetramino[0].y == 1)
		{
			//printf("NEW y = %d\n", tetramino[0].y);
			is_over = true;
		}
	}
	// Unless permanetly shift tetramion
	ResetKey();
	//-----Move End

	if (is_rotate_tetramino)
	{
		is_rotate_tetramino = false;
		WriteToBuffer(tetramino);
		RotateTetramino(GetBuffer());
		if (HasCollisionWithField(GetBuffer(), field))
		{
			//printf("#COLLISION\n");
			return;
		}
		RotateTetramino(tetramino);
	}
}

void Timer(int = 0)
{
	Renderer();
	Tick();
	if (is_down_key_pressed)
	{
		glutTimerFunc(pause / 5, Timer, 0);
		return;
	}
	glutTimerFunc(pause, Timer, 0);
}

void Keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_F11:
		//printf("F11 pause\n");
		is_pause = !is_pause;
		break;

	case GLUT_KEY_F12:
		//printf("F12 exit\n");
		//exit(0);
		is_over = true;
		break;

	case GLUT_KEY_LEFT:
		//printf("LEFT\n");
		KeyEvent(GLUT_KEY_LEFT);
		break;
	
	case GLUT_KEY_UP:
		is_rotate_tetramino = true;
		//printf("UP\n");
		break;

	case GLUT_KEY_RIGHT:
		//printf("RIGHT\n");
		is_rotate_tetramino = false;
		KeyEvent(GLUT_KEY_RIGHT);
		break;

	case GLUT_KEY_DOWN:
		//printf("DOWN\n");
		is_down_key_pressed = true;
		break;

	default:
		break;
	}
}
