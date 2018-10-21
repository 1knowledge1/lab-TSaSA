#include <iostream>
#include <math.h>
#include <iomanip>
int main()
{
	double e = 0.1, a = 0, b = 3, x, y;
	double N;
	N = (b-a) / e - 1;
	std::cout << "======================\n";
	std::cout << "|  N  |  x  |  f(x)  | \n"<<"======================\n";
	for (int i = 0; i <= N+1; ++i)
	{
		x = i*(b-a) / (N + 1);
		y = -sqrt(x)*sin(x);
		//std::cout << std::setprecision(3) << "| "<< x<< " | "<< y << " |\n";
		printf("| %d | %.3f | %.3f |", i, x, y);
		std::cout << "\n======================\n";
	}
	return 0;
}
