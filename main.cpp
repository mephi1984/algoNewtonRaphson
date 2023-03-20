#include <iostream>
#include <vector>
#include <array>
#include <cassert>
#include <chrono>
#include <algorithm>


//Variant 21
// f = sin(x) - x + 2.0
// x0 = 2.55
// Calc an integral function from it

double f(double x)
{
	return cos(x) + x * x / 2.0 - 2.0 * x;
}

double ff(double x)
{
	return -(sin(x) - x + 2.0);
}

double fff(double x)
{
	return -cos(x) + 1.0;
}

/*
double f(double x)
{
	return sin(x) - x + 2.0;
}

double ff(double x)
{
	return cos(x) - 1.0;
}

double fff(double x)
{
	return -sin(x);
}*/


void calcNewtonRaphson(double x0)
{
	double xprev = x0;

	double eps = 0.0000000001;
	double ffxprev;
	double fffxprev;
	int m = 0;

	do
	{
		ffxprev = ff(xprev);
		fffxprev = fff(xprev);
		double xnext = xprev - ffxprev / fffxprev;

		m++;

		std::cout << "Iteration just pased: " << m
			<< " xprev = " << xprev
			<< " ffxprev = " << ffxprev
			<< " fffxprev = " << fffxprev
			<< " xnext = " << xnext
			<< " eps = " << abs(ffxprev)
			<< std::endl;

		xprev = xnext;

	} while (abs(ffxprev) > eps);

	std::cout << " For eps = " << eps << " m = " << m << std::endl;
	std::cout << "Result: X=" << xprev << std::endl;
}


int main()
{
	double x0 = 2.55;

	calcNewtonRaphson(x0);

}