#include <string.h>
#include <conio.h>
#include <iostream.h>
#include "quiz.h"

int height, width;

void init_ui()
{
	struct text_info info;
	gettextinfo(&info);

	width = (int) info.screenwidth;
	height = (int) info.screenheight;

	frame();

	int lvl = lvl_inp_scr();  //Gets the difficulty level from user.
								//Also includes ui for that page

	clrscr();
	cout << "You selected " << lvl;

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
 Difficulty level input screen
*/
int lvl_inp_scr()
{
	gotoxy(1, (height - 6) / 2);
	printc("Some great awesome title here");
	cout << "\n\n";

	int a = (width - strlen("Select difficulty level: ")) / 2;
	coord b(a - 4,wherey());
	frame(b, 6, strlen("Select difficulty level: ") + 8, 0);

	printc("Select difficulty level: ", a);
	cout << '\n';


	int selected = 0; //Boolean value to express whether any option has been chosen
	int curr_line = 0; //Indicates the position of current line that is highlighted

	while(!selected)
	{
		gotoxy(wherex(), b.y + 3);
		printc("Easy", a); cout << '\n';
		printc("Intermediate", a); cout << '\n';
		printc("Hard", a); cout << '\n';

		//Highlighting the option to show current line
		for(int i = 0; i < 3; i++)
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
			curr_line %= 3;
			if(curr_line < 0)
			{
				curr_line += 3;
			}
		}
		else if(c == 13) //If enter was pressed
		{
			selected = 1;
		}
	}

	return curr_line; //The line that was selected
}