#include <stdio.h>

void main(void)
{
	char c;
	int charcount = 0, wordcount = 0, linecount = 1, flag = 0;
	while ((c = getchar()) != '#')
	{
		if (c == '\n')
		{
			linecount++;
		}
		if (c == '\n' || c == ' '|| c == '.')
		{
			flag = 0;
		}
		else 
		{
			charcount++; 
			if (!flag)
			{
				flag = 1;
				wordcount++;
			}			
		}
	}
	printf("Characters: %d   Words: %d   Lines: %d\n", charcount, wordcount, linecount);
}