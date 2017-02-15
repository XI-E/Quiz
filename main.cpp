#include "quiz.h"

extern question questions[3][3][3];

void main()
{
	clrscr();

	int play = 1;  //Boolean value indicating if user wants to play again

	while(play)
	{
		init_ques();
		init_ui();

		int lvl = generate_ui(1);  //Gets the difficulty level from user.
									//Also includes ui for that page

		int sub = generate_ui(2);  //Gets the subject from user

		play = ask_q(lvl, sub);
	}
}
