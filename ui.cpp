#include <string.h>
#include <conio.h>
#include "quiz.h"

int width = (int) info.screenwidth;
int height = (int) info.screenheight;

void init_ui()
{
	win_frame();
	gotoxy(1, (height - 6) / 2);
	printc("Some great awesome title here");
	cout << "\n\n";
	
	int a = (width - strlen("Select difficulty level: ")) / 2;
	printc("Select difficulty level: ", a);
	cout << '\n';
	
	
	int selected = 0; //Boolean value to express whether any option has been chosen
	int curr_line = 0; //Indicates the position of current line that is highlighted
	
	while(!selected)
	{
		printc("Easy", a); cout << '\n';
		printc("Intermediate", a); cout << '\n';
		printc("Hard", a); cout << '\n';
	
		//Highlighting the option to show current line
		gotoxy(a - 2, (height - 6) / 2 + 3 + curr_line);
		cout << (char) 175;
		
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
}

void printq(int a, int b, int c, int q_no)
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


}

void win_frame()
{
	char l_up = (char) 201;
	char l_down = (char) 200;
	char r_up = (char) 187;
	char r_down = (char) 188;
	char bet_ver = (char) 186;
	char bet_hor = (char) 205;

	struct text_info info;
	gettextinfo(&info);

	gotoxy(1,1);

	cout << l_up;
	for(int i = 0; i < width - 2; i++)
	{
		cout << bet_hor;
	}
	cout << r_up;

	for(i = 2; i <= height - 2; i++)
	{
		gotoxy(1, i); cout << bet_ver;
		gotoxy(width, i); cout << bet_ver;
	}

	gotoxy(1, height - 1);
	cout << l_down;
	for(i = 0; i < width - 2; i++)
	{
		cout << bet_hor;
	}
	cout << r_down;
}

void printc(char str[], int ws = -1, int t_color = WHITE, int b_color = BLACK)
{
	if(ws == -1)
	{
		gotoxy((width - strlen(str))/2 ,wherey());
	}
	else
	{
		gotoxy((width - ws) / 2, wherey());
	}
	
	textcolor(t_color);
	textbackground(b_color);
	cprintf("%s", str);
	cout << '\n';
}
