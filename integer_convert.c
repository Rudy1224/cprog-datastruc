#include <stdio.h>

void convert(int x)
{
	int n;
	if ((n = x / 10) != 0)
	{
		convert(n);
	}
	putchar(x % 10 + '0');
}

void main(void)
{
	int input;
	printf("Enter an integer: ");
	scanf("%d", &input);
	printf("Result: ");
	if (input < 0)
	{
		putchar('-');
		input = -input;
	}
	convert(input);
}