#include "quiz.hpp"

int height, width;

void init_ui()
{
	_setcursortype(_NOCURSOR); //hides cursor
	textcolor(LIGHTGRAY);
	textbackground(BLACK);

	struct text_info info;
	gettextinfo(&info);

	//height and witdth of screen
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
	//cout << 1;
	for(int i = 0; i < f_width - 2; i++)
	{
		cout << bet_hor;
		
		///*debug*/cout << (i + 2) % 10;
	}
	cout << r_up;
	//cout << f_width % 10;

	if(f_sides)
	{
		for(i = 0; i < f_height - 2; i++)
		{
			gotoxy(up_left.x, up_left.y + i + 1); cout << bet_ver;
			gotoxy(up_left.x + f_width - 1, up_left.y + i + 1); cout << bet_ver;
		}
	}

	gotoxy(up_left.x, up_left.y + f_height - 1);
	cout << l_down;
	//cout << 1;
	for(i = 0; i < f_width - 2; i++)
	{
		cout << bet_hor;
		//cout << (i + 2) % 10;
	}
	cout << r_down;
	//cout << f_width % 10;

	gotoxy(up_left.x + 2, up_left.y + 2);
}

void printc(char str[], int ws, int t_color, int b_color)
{
	if(ws == -1)
	{
		gotoxy((width - strlen(str))/2 + 1 ,wherey());
	}
	else
	{
		gotoxy(ws + 1, wherey());
	}

	textcolor(t_color);
	textbackground(b_color);
	cprintf("%s", str);
}

int select(coord bullet1, int num_ops, int height_ops[], int mode, char bullet)
{
	int curr_line = 0;
	gotoxy(bullet1.x, bullet1.y); cout << bullet;
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
		else if(c == 8)
		{
			if(mode == BCKSPC)
			{
				return -1;
			}
		}
		else if(c == 27)
		{
			if(mode == ESC)
			{
				return -2;
			}
		}
		
		for(int i = 0; i < num_ops; i++)
		{
			coord bullet_pos;
			
			bullet_pos.x = bullet1.x;
			bullet_pos.y = bullet1.y;
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

coord props(const int num_ops, char ops[][BIGSTRLEN(2)], char head[], coord& f_uleft, int ops_height[], int print_mode) 
{
	//Determining height and witdth of the frame
	
	int maxf_width = (8 * width)/10;
	int f_width = 0;
	int f_ws = 1; //Whitespace in frame from both sides
	int s_bullet = 2, s_num = 0; //Space needed for bullet amd numbering
	if(print_mode != NONUM)
	{
		s_num = 3;
	}
	
	int h_len, ops_len[SUB_MAX];
	h_len = strlen(head) + s_bullet;
	for(int i = 0; i < num_ops; i++)
	{
		ops_len[i] = strlen(ops[i]);
	}
	
	f_width = h_len + 2 * f_ws;
	if(f_width > maxf_width)
	{
		f_width = maxf_width;
	}
	
	for(i = 0; i < num_ops; i++)
	{
		int temp_width = ops_len[i] + 2 * f_ws + s_bullet + s_num;
		
		if(temp_width > maxf_width)
		{
			f_width = maxf_width;
			break;
		}
		else if(temp_width > f_width)
		{
			f_width = temp_width;
		}
	}
	f_width += 2; //2 added for the sides of frame
	
	int f_height = 2; //2 lines for frame itself
	f_height += 2; //2 lines, 1 from top and 1 from bottom left empty
	char fops[SUB_MAX][BIGSTRLEN(2)];
	char fhead[BIGSTRLEN(3)];
	int head_height;
	
	head_height = wrap(head,fhead,f_width - 2 * f_ws - 2); //-2 at the end because f_width includes sides of the frame as well
	f_height += head_height;
	
	for(i = 0; i < num_ops; i++)
	{
		ops_height[i] = wrap(ops[i],fops[i], f_width - 2 * f_ws - s_bullet - s_num - 2); //-2 at the end because f_width includes
																						 //sides of the frame as well
		f_height += ops_height[i];
	}
	
	//Determining upper left coordinates of frame
	f_uleft.x = (width - f_width) / 2 + 1;
	f_uleft.y = (height - f_height) / 2 + 1;
	
	//frame
	
	frame(f_uleft, f_height, f_width, NOSIDES);
	
	//Printing head and ops
	
	coord head_coord(f_uleft.x + f_ws + 1, f_uleft.y + 1 + 1);
	
	int line_num = 0;
	char line[BIGSTRLEN(2)];
	int read;
	int chars_read = 0;

	for(i = 0; i < head_height; i++)
	{
		sscanf(fhead + chars_read, "%[^\n]%*c%n", line, &read);
		gotoxy(head_coord.x + s_bullet, head_coord.y + line_num);
		cout << line;
		line_num++;
		chars_read += read;
	}
	
	coord bullet1(head_coord.x, head_coord.y + line_num);
	for(i = 0; i < num_ops; i++)
	{
		chars_read = 0;
		gotoxy(head_coord.x + s_bullet, head_coord.y + line_num);
		if(print_mode == ALPHA)
		{
			cout << (char) ('A' + i) << '.';
		}
		else if(print_mode == NUM)
		{
			cout << i + 1 << '.';
		}
		for(int j = 0; j < ops_height[i]; j++)
		{
			sscanf(fops[i] + chars_read, "%[^\n]%*c%n", line, &read);
			gotoxy(head_coord.x + s_bullet + s_num, head_coord.y + line_num);
			cout << line;
			line_num++;
			chars_read += read;
		}
	}
	
	return bullet1;
}

//Assumes outer frame is already present and there is place to print it all
void prhead(char left[], char middle[], char right[])
{
	gotoxy(2,2); cout << left;
	printc(middle);
	gotoxy(width-strlen(right), 2); cout << right;
}

void prfoot(char left[], char middle[], char right[])
{
	gotoxy(2, height - 1 - 1); cout << left;
	printc(middle);
	gotoxy(width - strlen(right), height - 1 - 1); cout << right;
}
