#include <string.h>
#include <conio.h>
#include <iostream.h>
#include "quiz.h"

extern question questions[3][3][3];

int height, width;

void init_ui()
{
	struct text_info info;
	gettextinfo(&info);

	width = (int) info.screenwidth;
	height = (int) info.screenheight;
}

/*void printq(int a, int b, int c, int q_no)
{
	struct text_info info;
	gettextinfo(&info);

	int width = (int) info.screenwidth;
	int height = (int) info.screenheight;

	int text_w = (9 * width) / 10; //Defines the minimum whitespace on both sides when printing the question
	int text_h = strlen(questions[a][b][c].q) / text_w;

	for(int i = 0; i < 4; i++)
	{
		text_h += strlen(questions[a][b][c].options[i]) / text_w;
	}

	text_h += 1;

	gotoxy(1, (height - text_h) / 2);


} */

void frame(coord up_left, int f_height, int f_width, int f_sides)
{
	char l_up = (char) 201;
	char l_down = (char) 200;
	char r_up = (char) 187;
	char r_down = (char) 188;
	char bet_ver = (char) 186;
	char bet_hor = (char) 205;

	if(up_left.x == -1)
	{
		coord b(1,1);
		up_left = b;
		f_width = width;
		f_height = height - 1;
	}

	gotoxy(up_left.x, up_left.y);

	cout << l_up;
	for(int i = 0; i < f_width - 2; i++)
	{
		cout << bet_hor;
	}
	cout << r_up;

	if(f_sides)
	{
		for(i = 2; i <= f_height - 1; i++)
		{
			gotoxy(up_left.x, i); cout << bet_ver;
			gotoxy(up_left.x + f_width - 1, i); cout << bet_ver;
		}
	}

	gotoxy(up_left.x, up_left.y + f_height + 1);
	cout << l_down;
	for(i = 0; i < f_width - 2; i++)
	{
		cout << bet_hor;
	}
	cout << r_down;

	gotoxy(up_left.x + 2, up_left.y + 2);
}

void printc(char str[], int ws, int t_color, int b_color)
{
	if(ws == -1)
	{
		gotoxy((width - strlen(str))/2 ,wherey());
	}
	else
	{
		gotoxy(ws, wherey());
	}

	textcolor(t_color);
	textbackground(b_color);
	cprintf("%s", str);
}

/*
 Generates user interface
 Screen_num:
	1: difficulty level
	2: Subject
*/
int generate_ui(int screen_num, int lvl, int sub, int q_num)
{
	clrscr();
	frame();

	char title[] = "SOME GREAT AWESOME TITLE HERE";
	char head[100], op1[100], op2[100], op3[100], op4[100];
	if(screen_num == 1)
	{
		strcpy(head, "Select difficulty level: ");
		strcpy(op1, "Easy");
		strcpy(op2, "Intermediate");
		strcpy(op3, "Hard");
		strcpy(op4, "");
	}
	else if(screen_num == 2)
	{
		strcpy(head, "Select subject: ");
		strcpy(op1, "Computer Science (C++)");
		strcpy(op2, "General Knowledge");
		strcpy(op3, "English");
		strcpy(op4, "");
	}
	else if(screen_num == 3)
	{
		strcpy(head, questions[lvl][sub][q_num].q);
		strcpy(op1, questions[lvl][sub][q_num].options[0]);
		strcpy(op2, questions[lvl][sub][q_num].options[1]);
		strcpy(op3, questions[lvl][sub][q_num].options[2]);
		strcpy(op4, questions[lvl][sub][q_num].options[3]);
	}

	gotoxy(1, (height - 6) / 2);

	if(screen_num == 3)
	{
		gotoxy(1, (height - 7) / 2);
	}

	printc(title);
	cout << "\n\n";

	int lengths[] = {
					  strlen(head),
					  strlen(op1),
					  strlen(op2),
					  strlen(op3),
					  strlen(op4)
					};

	//Determining max length
	int max_len = lengths[0];
	for(int i = 0; i < 5; i++)
	{
		for(int j = i + 1; j < 5; j++)
		{
			if(lengths[j] > max_len)
			{
				max_len = lengths[j];
			}
		}
	}

	int a = (width - max_len) / 2;
	coord b(a - 4,wherey());
	frame(b, (screen_num == 3 ? 7 : 6), max_len + 8, 0);

	printc(head, a);
	cout << '\n';

	int selected = 0; //Boolean value to express whether any option has been chosen
	int curr_line = 0; //Indicates the position of current line that is highlighted

	while(!selected)
	{
		gotoxy(wherex(), b.y + 3);
		printc(op1, a); cout << '\n';
		printc(op2, a); cout << '\n';
		printc(op3, a); cout << '\n';
		if(screen_num == 3)
		{
			printc(op4, a); cout << '\n';
		}

		int num;
		if(screen_num == 3)
		{
			num = 4;
		}
		else
		{
			num = 3;
		}

		//Highlighting the option to show current line
		for(int i = 0; i < num; i++)
		{
			if(i == curr_line)
			{
				gotoxy(a - 2, b.y + 3 + curr_line);
				cout << (char) 175;
			}
			else
			{
				gotoxy(a - 2, b.y + 3 + i);
				cout << ' ';
			}
		}
		//Detecting arrow keys
		char c = getch();
		if(c == 0)
		{
			c = getch();
			switch(c)
			{
				case 'H':
					curr_line--;
					break;
				case 'P':
					curr_line++;
					break;
			}
			curr_line %= num;
			if(curr_line < 0)
			{
				curr_line += num;
			}
		}
		else if(c == 13) //If enter was pressed
		{
			selected = 1;
		}
	}

	return curr_line; //The line that was selected
}