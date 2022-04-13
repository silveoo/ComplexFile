#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class complex 
{
public:
	double re;
	double i;
	complex() 
	{
		re = i = 0;
	}
	complex(int vre, int vi) 
	{
		re = vre;
		i = vi;
	}
};

double module(complex a) {
	return sqrt(pow(a.re, 2) + pow(a.i, 2));
}

int main() 
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	ifstream file;
	string a;
	int re = 0;
	int i = 0;
	double max = 0;
	file.open("complex.txt");
	int counter = 1;
	complex p[100];
	while(!file.eof())
	{
		file >> re;
		file >> i;
		p[counter] = complex(re, i);
		counter++;
		n++;
	}
	for (int z = counter; z != 0; z--)
	{
		if (module(p[z]) > max)
			max = module(p[z]);
	}
	cout << max;
}