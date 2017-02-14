#include <iostream.h>
#include <conio.h>
#include "quiz.h"

extern question questions[3][3][3];

void main()
{
	clrscr();

	init_ques();
	init_ui();

	getch();	
}
