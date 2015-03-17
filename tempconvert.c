#include <stdio.h>

void convert(float a)
{
	a = (9*a/5)+32;
	printf("Fahrenheit temperature is %.2f degrees.\n", a);
}

void main()
{
	float temp;
	printf("Enter Celsius temperature:");
	scanf("%f", &temp);
	convert(temp);
}