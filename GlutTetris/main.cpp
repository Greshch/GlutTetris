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
	
}
