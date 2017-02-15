#include "helpers.h"
#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>

int wrap(char inp_str[], char out_str[],int length)
{
	char word[30];

	int chars_read = 0;
	int read;
	int written = 0;
	int num_lines = 1;

	while(sscanf(inp_str + chars_read, "%s%n", word, &read) > 0)
	{
		if(written + strlen(word) > length)
		{
			strcat(out_str, "\n");
			num_lines++;
			strcat(out_str, word);
			strcat(out_str, " ");
			written = strlen(word) + 1;
		}
		else
		{
			strcat(out_str, word);
			strcat(out_str, " ");
			written += strlen(word) + 1;
		}
		chars_read += read;
	}
	
	return num_lines;
}
