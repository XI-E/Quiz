#include "helpers.h"

int wrap(char inp_str[], char out_str[],int length)
{
	char word[30];  //!< word extracted from inp_str

	int chars_read = 0; //!< total number of chararacter read from inp_str
	int read; //!< number of characters read for the current line
	int num_lines = 1; //!< Number of lines written into out_str

	while(sscanf(inp_str + chars_read, "%s%n", word, &read) > 0)
	{
		if(written + strlen(word) > length)
		{
			strcat(out_str, "\n");
			num_lines++;
			strcat(out_str, word);
			strcat(out_str, " ");
		}
		else
		{
			strcat(out_str, word);
			strcat(out_str, " ");
		}
		chars_read += read;
	}
	
	return num_lines;
}
