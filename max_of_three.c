#include <stdio.h>

void main()
{
	int a, b, c;
	printf("Please enter a, b and c:");
	scanf("%d %d %d", &a, &b, &c);
	if (a<b)
		if (b<c)
			a = c;
		else a = b;
	else
		if (a<c)
			a = c;
	printf("The maximun number is %d\n", a);
}
