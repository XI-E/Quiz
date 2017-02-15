#ifndef QUIZ_H
#define QUIZ_H

#include <conio.h>
#include "helpers.h"

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
	coord()
	{
		x = 0;
		y = 0;
	}
	int x;
	int y;
};

void frame (coord = coord(-1,-1), int = -1, int = -1, int = 1);
int generate_ui(int screen_num);
int generate_ui(int lvl, int sub, int q_num);
int ask_q(int lvl, int sub);

int select(coord line1, int num_ops, int height_ops[], char bullet = (char) 175);
int select(coord line1, int num_ops, char bullet = (char) 175);

#endif //QUIZ_H
