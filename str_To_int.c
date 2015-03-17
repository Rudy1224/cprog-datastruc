#include <stdio.h>

void str_To_int()
{
	char x[10];
	int i = 0, num = 0, flag = 0;
	printf("Input the number: ");
	scanf_s("%s", &x, 9);
	if (x[0] == '-')
	{
		flag = 1;
		i++;
	}
	while(x[i] != '\0')
	{
		num = num * 10 + (x[i] - '0');
		i++;
	}
	if (flag == 1)
		printf("The number is %d.\n", num*(-1));
	else
		printf("The number is %d.\n", num);
}

void main()
{
	while (1)
		str_To_int();
}