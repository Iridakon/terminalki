#include <stdio.h>
#include <math.h>
#include <locale.h>
#define p 3.1415

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите числа a, b,n, где a, b - коэфиценты в записи a+i*b, а n- степень \n");
	double r = 0, a = 0, b = 0, n = 0, f=0;
	scanf_s("%lf %lf %lf", &a, &b,&n);
	r = sqrt(a * a + b * b);
	double s = 0, c = 0;
	c = a / r;
	f = b>0? acos(c): -acos(c);
	c = f / p;
	printf("0. z= %f (cos %f p + i*sin %f p)\n", r, c, c);
	double a1 = 0, b1 = 0;
	a1 = a / r;
	b1 = -b / r;
	printf("1. z^(-1)= %lf +( %lf)*i \n", a1,b1);
	double r1 = pow(r, n);
	printf("2. z^n= %lf (cos %f p + i sin %f p)\n", r1, c*n, c * n);
	double r2 = pow(r, -n);
	double del = 2 * p/n;
	printf("2. z^-n= \n");
	for (int i = 0; i < n; i++) {
		c = (c+2*p*i)/n;

		printf("     = %lf (cos %f p + i sin %f p)\n", r2, c,c);
	}
	return 0;
}
