#include <iostream>
#include <math>
using namespace std;
int main(int argc, char const *argv[])
{
	int i = 785;
	float f = 1.5678*8;
	double d = 1.5*pow(2,100);

	cout <<" i = " << i << " f= " << f << " d= " << d<< endl;

	i = (int)(float)i;
	float f1= (float)(int)f;

	cout <<" i = " << i << " f1= " << f1 << " d= " << d<< endl;

	float f2 = (float)(double)f;
	// d = (float)(double)

	return 0;
}