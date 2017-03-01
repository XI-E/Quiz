#include "quiz.hpp"

int sub_num, lvl;
char lefthead[STDSTRLEN] = "Difficulty: ";
char righthead[STDSTRLEN] = "Subject: ";
int total_correct, ques_attempted;

int prscr(int screen_num)
{
	coord f_uleft, bullet1;
	int response, height_ops[SUB_MAX];
	switch(screen_num)
	{
		//Screen 1: Select Subject
		case 1:
			{
				clrscr();
				frame();
				char sub_names[SUB_MAX][BIGSTRLEN(2)];
				for(int i = 0; i < num_subs; i++)
				{
					strcpy(sub_names[i], subs[i].sub_name);
				}
			
				bullet1 = props(num_subs, sub_names, "Select Subject:", f_uleft, height_ops, NUM);
				gotoxy(1, f_uleft.y - 2);
				printc(TITLE);
				response = select(bullet1, 3, height_ops);
			
				return response;
			}
		//Screen 2: Select Difficulty
		case 2:
			{
				clrscr();
				frame();
				prhead("", "Press BACKSPACE to go back", righthead);
				char diff_levels[3][BIGSTRLEN(2)] = {"Easy", "Intermediate", "Hard"};
				bullet1 = props(3, diff_levels, "Select difficulty level:", f_uleft, height_ops);
				gotoxy(1, f_uleft.y - 2);
				printc(TITLE);
				response = select(bullet1, 3, height_ops, BCKSPC);
				
				return response;
			}
			
		//Screen 3: Questions
		case 3:
			{
				int num_ques = subs[sub_num].q_per_level[lvl];
			
				int q_asked[MAXQPERLVL];
				for(int i = 0; i < num_ques; i++)
				{
					q_asked[i] = 0;
				}
				total_correct = 0;
				ques_attempted = 0;
			
				for(i = 0; i < num_ques; i++)
				{				
					//Determining question number
					time_t t;
					srand((unsigned) time(&t));
					int q_num;
					do
					{
						q_num = rand() % num_ques;
					}
					while(q_asked[q_num] == 1);
					q_asked[q_num] = 1;
				
					//Initialising ques with the question
					question ques;
					init_ques(lvl, sub_num, q_num, ques);
				
					//Randomising the order of options and setting the correct option number
					//according to the new order
					int op_chosen[4], op_order[4], op_num = 0;
					for(int j = 0; j < 4; j++)
					{
						op_chosen[j] = 0;
					}
				
					srand((unsigned) time(&t));
					for(j = 0; j < 4; j++)
					{
						do
						{
							op_num = rand() % 4;
						}
						while(op_chosen[op_num] == 1);
					
						op_chosen[op_num] = 1;
						op_order[j] = op_num;
					}
				
					int correct;
					for(j = 0; j < 4; j++)
					{
						if(ques.correct == op_order[j])
						{
							correct = j;
						}
					}
				
					//Setting the options according to order
					char ordered_ops[4][BIGSTRLEN(2)];
					for(j = 0; j < 4; j++)
					{
						strcpy(ordered_ops[j], ques.options[op_order[j]]);
					}
				
					//Printing the options
					clrscr();
					frame();
					char centerhead[STDSTRLEN] = "Question ";
					char a[2]; itoa(i+1, a, 10);
					strcat(centerhead, a);
					prhead(lefthead, centerhead, righthead);
					prfoot("", "Press ESC to end the round", "");
					bullet1 = props(4, ordered_ops, ques.q, f_uleft, height_ops, ALPHA);
					gotoxy(1, f_uleft.y - 2 - 2);
					printc(TITLE);
					response = select(bullet1, 4, height_ops, ESC);
					
					if(response == -2)
					{
						break;
					}

					gotoxy(1, f_uleft.y - 2);
					ques_attempted++;
					if(response == correct)
					{
						printc("Correct Answer!");
						total_correct++;
					}
					else
					{
						char out[STDSTRLEN] = "Incorrect Answer! The correct answer was ";
						char a[] = {(char) ('A' + correct), '\0'};
						strcat(out, a);
						printc(out);
					}
					
					getch();
				}
				return 0;
			}
		//Screen 4: Result and asking user if he wants to play again
		case 4:
			{
				clrscr();
				frame();
				prhead(lefthead, "", righthead);
				gotoxy(1, 5); printc(TITLE);
			
				int len = strlen("You got _ out of _ questions correct");			
				gotoxy((width - len) / 2 + 1, (height - 3) / 2 + 1);
				cout << "You got " << total_correct << " out of " << ques_attempted << " questions correct";
				cout << endl << endl;
				printc("Do you want to play again (y/n) ?");
				while(1)
				{
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
	}
	return -1;
}

int play()
{
	do
	{
		strcpy(righthead, "Subject: ");
		sub_num = prscr(1);
		strcat(righthead, subs[sub_num].short_name);
	
		lvl = prscr(2);
	}
	while(lvl == -1);
	
	strcpy(lefthead, "Difficulty: ");
	switch(lvl)
	{
		case 0:
			strcat(lefthead, "Easy");
			break;
		case 1:
			strcat(lefthead, "Intermediate");
			break;
		case 2:
			strcat(lefthead, "Hard");
			break;
	}
	
	prscr(3);
	
	return prscr(4);
}
