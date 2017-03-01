#include "quiz.hpp"

void main()
{
	clrscr();
	init_ui();
	init_qinfo();
	
	int play_again;
	
	do
	{
		play_again = play();
	}
	while(play_again == 1);
}
