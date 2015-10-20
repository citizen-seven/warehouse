#include <stdio.h>
#include <math.h>

// The function, who calculate roots of quadratic equation
int square(double a, double b, double c, double* x);

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	scanf ("%5lg %5lg %5lg", &a, &b, &c);
	double x[2] = {0, 0};
	int tmp = square (a, b, c, x);
	if (tmp == 0)
	   printf("X1 = %lg X2 = %lg", x[0], x[1]);
	if (tmp == 1)
	   printf("X - any rational number");
	if (tmp == 2)
	   printf("there is no such X");
	if (tmp == 3)
	   printf("X1 = %lg ", x[0]);
	return 0;
}


int square(double a, double b, double c, double* x)
{
	if (a == 0)
		if (b == 0)
			if (c == 0)
				return 1;
			else
				return 2;
		else
			{
                x[0] = -c / b;
                return 3;
            }
	else
	{
        if (a*c < 0)
        {
            x[0] = sqrt(-c / a);
            x[1] = - sqrt(-c / a);
            return 0;
        }
        else
            return 2;
    }
	double disk = b*b - 4*a*c;
	if (disk >= 0)
	{
		x[0] = (-b + sqrt(disk)) / (2*a);
		x[1] = (-b - sqrt(disk)) / (2*a);
	} else
		return -1;
	if (x[0] == x[1])
		return 3;
	return 0;
}
