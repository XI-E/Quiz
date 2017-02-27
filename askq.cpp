#include "quiz.h"

extern question questions[3][3][3];
extern height;
extern width;

int ask_q(int lvl, int sub)
{
	int correct_ans = 0; //!< Number of questions answered correctly
	for(int i = 0; i < 3; i++)
	{		
		int is_correct = generate_ui(lvl, sub, i); //!< Determines if the option chosen by the user is correct or not
				
		if(is_correct)
		{
			correct_ans++;
		}
		getch();
	}

	clrscr();

	while(1)
	{
		frame();
		gotoxy((width - strlen("You got _ out of 3 questions correct")) / 2 + 1, (height - 3) / 2 + 1);
		cout << "You got " << correct_ans << " out of 3 questions correct\n\n";
		printc("Do you want to play again? (y/n)");
		char response = getch(); //!< Response from the user whether to play again or not
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
