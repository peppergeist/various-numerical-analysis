/*
	COLTON WILLIAMS 2017
	NUMERICAL ANALYSIS
	ZETA FUNCTION
*/

#define ZETA2 1.6449340668482264
#define ZETA3 1.20205690315959

#include <stdio.h>
#include <math.h>

float zeta_forward(int s, int n)
{
	float total = 0.0;
	int N = (int)pow(10, n);
	for (int i = 1; i < N + 1; ++i)
	{
		total = total + 1.0/(pow(i, s));
	}
	return total;
}

float zeta_backward(int s, int n)
{
	float total = 0.0;
	int N = (int)pow(10, n);
	for (int i = N + 1; i > 0; --i)
	{
		total = total + 1.0/(pow(i, s));
	}
	return total;
}

int main()
{
	printf("ENTER A VALUE FOR S :: ");
	int s, n;
	scanf("%d", &s);
	printf("ENTER A VALUE FOR N :: ");
	scanf("%d", &n);
	printf("zeta_forward(%d) \t%f\n", s, zeta_forward(s, n));
	printf("zeta_backward(%d)\t%f\n", s, zeta_backward(s, n));
	printf("zeta(2)-forward  \t%f\n", ZETA2 - zeta_forward(s, n));
	printf("zeta(2)-backward \t%f\n", ZETA2 - zeta_backward(s, n));
	printf("zeta(3)-forward  \t%f\n", ZETA3 - zeta_forward(s, n));
	printf("zeta(3)-backward \t%f\n", ZETA3 - zeta_backward(s, n));
	return 0;
}