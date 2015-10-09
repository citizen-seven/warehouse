#include <stdio.h>
#include <math.h>

int square( double a, double b, double c, double* x);  // The function, who calculate roots of quadratic equation

int main ( )
{
	double a = 0;
	double b = 0;
	double c = 0;
	scanf ("%lg %lg %lg", &a, &b, &c);
	double x[2] = {0, 0};
	square (a, b, c, x);
	if (square (a, b, c, x) != -1)
	   printf("%lg %lg", x[0], x[1]);
	else
	   printf("No");
	return 0;
}


int square( double a, double b, double c, double* x)
{
	double disk = b*b - 4*a*c;
	if (disk >= 0) {
		x[0] = (-b+sqrt(disk)) / (2*a);
		x[1] = (-b-sqrt(disk)) / (2*a);
	} else {
	return -1;
	}
	return 0;
}
