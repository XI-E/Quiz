#ifndef QUIZ_H
#define QUIZ_H

#include <conio.h>

struct question
{
	char q[200];
	char options[4][100];
	int correct;
};

void init_ques();
void init_ui();
void win_frame();
void printc(char*, int = (-1), int = WHITE, int = BLACK);

struct coord
{
	coord(int x_inp, int y_inp)
	{
		x = x_inp;
		y = y_inp;
	}
	int x;
	int y;
};

void frame (coord = coord(-1,-1), int = -1, int = -1, int = 1);
int lvl_inp_scr();
#endif //QUIZ_H
