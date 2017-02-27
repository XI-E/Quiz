#include "quiz.h"

extern question questions[3][3][3];

void main()
{
	clrscr();

	//! Boolean value indicating if user wants to play again
	int play = 1;  

	while(play)
	{
		init_ques();
		init_ui();

		int lvl = generate_ui(1);  

		int sub = generate_ui(2);  

		play = ask_q(lvl, sub);
	}
}
