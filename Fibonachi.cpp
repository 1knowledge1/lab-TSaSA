#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

class Fibonachi
{
private:
	double a, b, e, delta = 0.05;
	double x1, x2, y1, y2;
	double* FibonachiSquence;
	int N;

	
	void algorithm(int counter);

public:
	Fibonachi();
	~Fibonachi();

	void SearchOfSquence();

	void minFib();
	bool input( std::istream & stream);
	std::ostream & write(std::ostream  & stream) const;
};
Fibonachi::Fibonachi()
{
	a = b = e = N =0;
	x1 = x2 = y1 = y2 = 0;
	FibonachiSquence = nullptr;
}
Fibonachi::~Fibonachi()
{
	if (FibonachiSquence != nullptr)
	{
		delete[] FibonachiSquence;
	}
}
void Fibonachi::SearchOfSquence()
{
	std::vector<int> FibSque = { 1, 1 };
	int F = 1, Fn = 1, temp;

	double lim = (b - a) / e;
	while (Fn < lim)
	{
		temp = Fn;
		Fn += F;
		F = temp;
		FibSque.push_back(Fn);
	}
	FibonachiSquence = new double [FibSque.size()];
	for (int i = 0; i < FibSque.size(); ++i)
	{
		FibonachiSquence[i] = FibSque[i];
		//std::cout << FibonachiSquence[i] << ' ';
	}
	N = FibSque.size()-1;

}
bool Fibonachi::input(std::istream & stream) // Формат ввода: a b e
{
	if (stream >> a && stream >> b && stream >> e) return true;
	else 
	{
		std::cout << "Error of input\n";
		return false;
	}
}

void Fibonachi::algorithm(int counter)
{
	if (counter < N - 2)
	{
		//y1 = x1*x1 + 2 * x1;
		//y2 = x2*x2 + 2 * x2;
		y1 = -sqrt(x1)*sin(x1);
		y2 = -sqrt(x2)*sin(x2);
		std::cout<<counter<< ": ["<< std::setprecision(4)<<a<<" , "<<b<<"]\n" <<"x1= "<< x1 << " x2= " << x2 << " y1= " << y1 << " y2= " << y2 << '\n'<<"---------"<< '\n';
		if (y1 < y2)
		{
			b = x2;
			x2 = x1;
			x1 = a + (FibonachiSquence[N - 2 - counter] / FibonachiSquence[N - counter])*(b - a);
			counter++;
			algorithm(counter);
		}
		else
		{
			if (y1 > y2)
			{
				a = x1;
				x1 = x2;
				x2 = a + (FibonachiSquence[N - 1 - counter] / FibonachiSquence[N - counter])*(b - a);
				counter++;
				algorithm(counter);
			}
			else
			{
				std::cout << "y1 = y2\n";
				return;
			}
		}
	}
	else return;
}

void Fibonachi::minFib()
{
	double min = 0;

	SearchOfSquence();
	int counter = 0;
	x1 = a + (FibonachiSquence[N - 2] / FibonachiSquence[N])*(b - a);
	x2 = a + (FibonachiSquence[N - 1] / FibonachiSquence[N])*(b - a);
	algorithm(counter);
	if (y1 > y2)
	{
		x2 += delta;
		//y2 = x2*x2 + 2 * x2;
		y2 = -sqrt(x2)*sin(x2);
	}
	else if (y1 > y2)
	{
		x1 += delta;
		//y1 = x1*x1 + 2 * x1;
		y1 = -sqrt(x1)*sin(x1);
	}

	if (y1 > y2)
	{
		a = x1;
		min = (a + b) / 2;
	}
	else if (y1 < y2)
	{
		b = x2;
		min = (a + b) / 2;
	}
	std::cout << counter << ": [" << std::setprecision(4) << a << " , " << b << "]\n" << "x1= " << x1 << " x2= " << x2 << " y1= " << y1 << " y2= " << y2 << '\n' << "---------" << '\n';
	std::cout << "Min: " << min << '\n';
}

int main()
{
	std::ifstream fin("file.txt");
	if (fin.is_open()) 
	{

		Fibonachi S;
		S.input(fin);
		//S.SearchOfSquence();
		S.minFib();

	}
	else std::cout << "File isn't open\n";
	return 0;
}
