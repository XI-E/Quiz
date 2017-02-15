#include <string.h>
#include <conio.h>
#include <iostream.h>
#include "quiz.h"
#include <stdio.h>

#define TITLE "Some Great Awesome Title Here"

extern question questions[3][3][3];

int height, width;

void init_ui()
{
	struct text_info info;
	gettextinfo(&info);

	width = (int) info.screenwidth;
	height = (int) info.screenheight;
}

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
int generate_ui(int screen_num)
{
	clrscr();
	frame();

	char title[] = TITLE;
	char head[100], op1[100], op2[100], op3[100];
	if(screen_num == 1)
	{
		strcpy(head, "Select difficulty level: ");
		strcpy(op1, "Easy");
		strcpy(op2, "Intermediate");
		strcpy(op3, "Hard");
	}
	else if(screen_num == 2)
	{
		strcpy(head, "Select subject: ");
		strcpy(op1, "Computer Science (C++)");
		strcpy(op2, "General Knowledge");
		strcpy(op3, "English");
	}

	gotoxy(1, (height - 6) / 2);

	printc(title);
	cout << "\n\n";

	int lengths[] = {
					  strlen(head),
					  strlen(op1),
					  strlen(op2),
					  strlen(op3),
					};

	//Determining max length
	int max_len = lengths[0];
	for(int i = 0; i < 4; i++)
	{
		for(int j = i + 1; j < 4; j++)
		{
			if(lengths[j] > max_len)
			{
				max_len = lengths[j];
			}
		}
	}

	int a = (width - max_len) / 2;
	coord b(a - 4,wherey());
	frame(b, 6, max_len + 8, 0);

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

		//Highlighting the option to show current line
		int num_op = 3;            //Number of options
		for(int i = 0; i < num_op; i++)
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
			curr_line %= num_op;
			if(curr_line < 0)
			{
				curr_line += num_op;
			}
		}
		else if(c == 13) //If enter was pressed
		{
			selected = 1;
		}
	}

	return curr_line; //The line that was selected
}

int generate_ui(int lvl, int sub, int q_num)
{
	clrscr();
	frame();

	char ques[200], options[4][200];

	strcpy(ques, questions[lvl][sub][q_num].q);
	strcpy(options[0], questions[lvl][sub][q_num].options[0]);
	strcpy(options[1], questions[lvl][sub][q_num].options[1]);
	strcpy(options[2], questions[lvl][sub][q_num].options[2]);
	strcpy(options[3], questions[lvl][sub][q_num].options[3]);

	int f_width = (8 * width) / 10;
	int ws = (width - f_width) / 2;

	int lengths[] = {
					 strlen(ques),
					 strlen(options[0]),
					 strlen(options[1]),
					 strlen(options[2]),
					 strlen(options[3])
					};

	int f_height = 2 + lengths[0] / f_width + 1;
	int f_ws = 3;  //Whitespace inside frame for options
	for(int i = 1; i < 5; i++)
	{
		f_height += lengths[i] / (f_width - f_ws) + 1;
	}

	coord u_left(ws + 1, (height - f_height) / 2 + 1);
	frame(u_left, f_height, f_width, 0);

	char fstring[200] = "";



	wrap(ques, fstring, f_width - f_ws);

	int line_num = 1;
	char line[200];
	int read;
	int chars_read = 0;
	while(sscanf(fstring + chars_read, "%[^\n]%*c%n", line, &read) > 0)
	{
		gotoxy(u_left.x + 2, u_left.y + line_num + 1);
		cout << line;
		line_num++;
		chars_read += read;
		if(chars_read >= strlen(fstring))
		{
			break;
		}
	}

	strcpy(fstring, "");

	int selected = 0; //Boolean value to express whether any option has been chosen
	int curr_line = 0; //Indicates the position of current line that is highlighted
	while(!selected)
	{
		for(i = 0; i < 4; i++)
		{
			wrap(options[i], fstring, f_width - f_ws - 3 - 2);
			read = 0, chars_read = 0;

			gotoxy(u_left.x + 2 + 3, u_left.y + line_num + 1);
			cout << (char) ('A' + i) << ". ";

			int len = strlen(fstring);
			fstring[len] = '\n'; fstring[len+1] = '\0';

			while(sscanf(fstring + chars_read, "%[^\n]%*c%n", line, &read) > 0)
			{
				gotoxy(u_left.x + 2 + 3 + 3, u_left.y + line_num + 1);
				cout << line;
				line_num++;
				chars_read += read;
				if(chars_read >= strlen(fstring))
				{
					break;
				}
			}

			strcpy(fstring, "");
		}
		
		//Highlighting the option to show current line
		int num_op = 4;            //Number of options
		for(int i = 0; i < num_op; i++)
		{
			if(i == curr_line)
			{
				gotoxy(u_left.x + 2, u_left.y + 2 + lengths[0] + i);
				cout << (char) 175;
			}
			else
			{
				gotoxy(u_left.x + 2, u_left.y + 2 + lengths[0] + i);
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
			curr_line %= num_op;
			if(curr_line < 0)
			{
				curr_line += num_op;
			}
		}
		else if(c == 13) //If enter was pressed
		{
			return curr_line;
		}
	 }


	return 0;
}
