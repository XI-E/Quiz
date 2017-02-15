#include <string.h>
#include <conio.h>
#include <iostream.h>
#include "quiz.h"
#include <stdio.h>
#include <process.h>
#include <dos.h>

#define TITLE "SOME GREAT AWESOME TITLE HERE"

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
		gotoxy(ws + 1, wherey());
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
	
	coord bullet1(b.x + 2, wherey());
	
	gotoxy(bullet1.x + 2, bullet1.y); printc(op1, a); cout << '\n';
	gotoxy(bullet1.x + 2, bullet1.y + 1); printc(op2, a); cout << '\n';
	gotoxy(bullet1.x + 2, bullet1.y + 2); printc(op3, a); cout << '\n';
	
	return select(bullet1, 3);
}

int generate_ui(int lvl, int sub, int q_num)
{
	clrscr();
	frame();

	gotoxy(2,2); cout << "Difficulty: ";
	switch(lvl)
	{
		case 0:
			cout << "Easy";
			break;
		case 1:
			cout << "Intermediate";
			break;
		case 2:
			cout << "Hard";
			break;
	}
	
	char print[100] = "Subject: ";
	switch(sub)
	{
		case 0:
			strcat(print, "C++");
			break;
		case 1:
			strcat(print, "G.K.");
			break;
		case 2:
			strcat(print, "English");
			break;
	}
	gotoxy(width - strlen(print), 2);
	cout << print;
	
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
	
	char printq[] = "Question ";
	gotoxy((width - strlen(printq) - 1) / 2 + 1, 2);
	cout << printq << q_num + 1;
	
	gotoxy(1, (height - f_height) / 2 - 3);
	printc(TITLE);

	char fstring[200] = "";

	int height_ops[4] = {0,0,0,0};
	int height_ques = wrap(ques, fstring, f_width - f_ws);

	int line_num = 1;
	char line[200];
	int read;
	int chars_read = 0;
	coord ques_coord(u_left.x + 1, u_left.y + 2);

	for(i = 0; i < height_ques; i++)
	{
		sscanf(fstring + chars_read, "%[^\n]%*c%n", line, &read);
		gotoxy(ques_coord.x + 2, ques_coord.y + line_num - 1);
		cout << line;
		line_num++;
		chars_read += read;
	}

	strcpy(fstring, "");

	coord bullet1(ques_coord.x, ques_coord.y + height_ques);

	for(i = 0; i < 4; i++)
	{
		height_ops[i] = wrap(options[i], fstring, f_width - f_ws - 3 - 2);
		read = 0, chars_read = 0;

		int len = strlen(fstring);
		fstring[len] = '\n'; fstring[len+1] = '\0';

		coord op_start(bullet1.x + 2 + 3, bullet1.y); // x: +2 space for bullet, +3 space for option letter
		
		for(int j = 0; j < i; j++)
		{
			op_start.y += height_ops[j];
		}
		
		gotoxy(bullet1.x + 2, op_start.y);
		cout << (char) ('A' + i) << ". ";
		
		for(j = 0; j < height_ops[i]; j++)
		{
			sscanf(fstring + chars_read, "%[^\n]%*c%n", line, &read);
			gotoxy(op_start.x, op_start.y + j);
			line_num++;
			cout << line;
			chars_read += read;
		}

		strcpy(fstring, "");
	}
	
	int selected_ans = select(bullet1, 4, height_ops) + 1;
	gotoxy(1, (height - f_height) / 2 - 1);
	if(selected_ans == questions[lvl][sub][q_num].correct)
	{
		printc("Correct Answer!!");
		return 1;
	}
	else
	{
		char pr[] = "Incorrect Answer!! Correct answer was "; 
		char a[2] = {(char) ('A' + questions[lvl][sub][q_num].correct - 1),'\0'};
		strcat(pr,a);
		printc(pr);
		return 0;
	}
	
}

int select(coord line1, int num_ops, char bullet)
{
	int height_ops[] = {1,1,1,1,1};
	return select(line1, num_ops, height_ops, bullet); 
}

int select(coord line1, int num_ops, int height_ops[], char bullet)
{
	int curr_line = 0;
	gotoxy(line1.x, line1.y); cout << bullet;
	while(1)
	{
		char c = getch();
		
		if(c == 0)
		{
			c = getch();
			switch(c)
			{
				case 'H':
					curr_line == 0 ? curr_line = num_ops - 1 : curr_line--;
					break;
				case 'P':
					curr_line == num_ops - 1 ? curr_line = 0 : curr_line++;
					break;
			}
		}
		else if(c == 13)
		{
			return curr_line;
		}
		
		for(int i = 0; i < num_ops; i++)
		{
			coord bullet_pos;
			
			bullet_pos.x = line1.x;
			bullet_pos.y = line1.y;
			for(int j = 0; j < i; j++)
			{
				bullet_pos.y += height_ops[j];
			}
			
			gotoxy(bullet_pos.x, bullet_pos.y);
			
			if(i == curr_line)
			{
				cout << bullet;
			}
			else
			{
				cout << ' ';
			}
		}	
	}
}
