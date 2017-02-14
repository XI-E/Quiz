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

#endif //QUIZ_H
