#include <stdio.h>
#include <math.h>

double f(double x)
{
	return x*x - x - 1;
}

void newtonMethod(void)
{
	double x = 1.6, diff = 1.0;
	int n = 0;
	while (fabs(diff) > (1e-15))
	{
		diff = f(x) / (2.0*x - 1);
		x = x - f(x) / (2.0*x - 1);
		++n;
	}
	printf("x = %.16f\ndiff = %.16f\nitertimes = %d\n", x, diff, n);
}

int bisectionMethod(void)
{
	double x = 1.6, y = 2.0, diff = 1.0;
	int n = 0;
	if (f(x)*f(y) >= 0)
	{
		printf("%s", "Range Error!");
		return 0;
	}
	while (fabs(diff) > (1e-15))
	{
		if (f((x + y) / 2.0) < 0)
		{
			x = (x + y) / 2.0;
		}
		else
		{
			y = (x + y) / 2.0;
		}
		diff = y - x;
		++n;
	}
	printf("x = %.16f\ndiff = %.16f\nitertimes = %d\n", x, diff, n);
	return 0;
}

void main(void)
{
	newtonMethod();
	bisectionMethod();
}