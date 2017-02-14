#include <iostream.h>
#include <conio.h>
#include <time.h>
#include "quiz.h"

extern question questions[3][3][3];

int ask_q(int lvl, int sub)
{
	for(int i = 0; i < 3; i++)
	{
		int selected_ans = generate_ui(3, lvl, sub, i) + 1;
		if(selected_ans == questions[lvl][sub][i].correct)
		{
			cout << "Correct Answer";
		}
		else
		{
			cout << "Incorrect Answer";
		}
		getch();
	}

	clrscr();

	while(1)
	{
		cout << "Do you want to play again? (y/n)";
		char c = getch();
		switch(c)
		{
			case 'y':
			case 'Y':
				return 1;
			case 'n':
			case 'N':
				return 0;
		}
	}
}