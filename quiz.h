#ifndef QUIZ_H
#define QUIZ_H

#include "helpers.h"
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct question
{
	char q[200];
	char options[4][100];
	int correct;
};

//ques.cpp
void init_ques();

//ui.cpp
void init_ui();
void win_frame();
void printc(char*, int = (-1), int = LIGHTGRAY, int = BLACK);

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
int select(coord line1, int num_ops, int height_ops[], char bullet = (char) 175);
int select(coord line1, int num_ops, char bullet = (char) 175);

//askq.cpp
int ask_q(int lvl, int sub);

#endif //QUIZ_H
