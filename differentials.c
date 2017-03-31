/*
	COLTON WILLIAMS 2017
	NUMERICAL ANALYSIS
	DIFFERENTIAL ESTIMATIONS
*/

// function used is f = y' = y - 4t^2 + 1 with y(0) = 1.0, on [0, 1]
// exact solution: y(t) = 4t^2 + 8t - 6e^t + 7, y(1.0) = 2.690309
// TODO allow passing of anonymous functions to estimations, not just f defined explicitly

#include <stdio.h>
#include <math.h>

double f(double t, double w)
{
	return w - 4 * t * t + 1;
}

double exact(double t)
{
	return 4 * t * t + 8 * t - (6 * exp(t)) + 7;
}

void euler(double a, double b, int steps, double init)
{
	double h = (b-a)/(double)steps;
	double t = a;
	double w = init;
	printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	for (int i = 1; i <= steps; ++i)
	{
		w = w + h * f(t, w);
		t = a + i * h;
		printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	}
}

void modified_euler(double a, double b, int steps, double init)
{
	double h = (b-a)/(double)steps;
	double t = a;
	double w = init;
	printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	for (int i = 1; i <= steps; ++i)
	{
		w = w + h * 0.5 * (f(t, w) + f(a + i * h, w + h * f(t, w)));
		t = a + i * h;
		printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	}
}

void runge_kutta(double a, double b, int steps, double init)
{
	double h = (b-a)/(double)steps;
	double t = a;
	double w = init;
	printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	double k1, k2, k3, k4;
	for (int i = 1; i <= steps; ++i)
	{
		k1 = h * f(t, w);
		k2 = h * f(t + h / 2, w + k1 / 2);
		k3 = h * f(t + h / 2, w + k2 / 2);
		k4 = h * f(t + h, w + k3);

		w = w + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		t = a + i * h;
		printf("(%f, %f)\t ERROR: %f\t\n", t, w, fabs(exact(t) - w));
	}
}

int main()
{
	euler(0.0, 1.0, 20, 1.0);
	modified_euler(0.0, 1.0, 20, 1.0);
	runge_kutta(0.0, 1.0, 20, 1.0);
	return 0;
}