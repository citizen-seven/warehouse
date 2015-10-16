#include <stdio.h>
#include <math.h>

/*
The program looks neat. 
You have comment about function purpose - that is great. It is better though to put it before the prototype

1) Correct calculation of roots. You must not give an array implicitly! 
2) add more cases like: a = 0, b = 0, c = 0
                        a = 0, b = 0, c != 0
                        and so on...
3) SUGGESTION: print something more than just "No" if you could not calculate roots. 
   it is also connected with the previous point. Smth like "No real roots",
   "Infinite nimber of roots", etc.
4) See comment below for aother inaccuracy
*/

// The function, who calculate roots of quadratic equation
int square(double a, double b, double c, double* x);

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double x[2] = {0, 0};
	scanf ("%lg %lg %lg", &a, &b, &c);
    square (a, b, c, x);
	// you calculate twice. you do not need this by two reasons:
    // 1) errors can occur on both cases. if you handle them in one case, you forgot about the other
    // 2) time is money. no need for unnecessary calculations
    if (square (a, b, c, x) != -1)
	   printf("%lg %lg", x[0], x[1]);
	else
	   printf("No");
	return 0;
}


int square(double a, double b, double c, double* x)
{
	double disk = b*b - 4*a*c;
	if (disk >= 0) 
	{
		// This is incorrect. the function does not know the size of your double array (x)
        // x[2] will give you error
        x[0] = (-b+sqrt(disk)) / (2*a);
		x[1] = (-b-sqrt(disk)) / (2*a);
	} else 
		return -1;
	return 0;
}
