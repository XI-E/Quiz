#include <iostream.h>
#include <conio.h>
#include "quiz.h"

void main()
{
	clrscr();
	
	init_ques();
	init_ui();
	
	cout << questions[0][1][2].q;
	
	getch();	
}
