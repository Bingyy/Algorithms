#include <iostream>
#include <cmath>
using namespace std;
#define INF 100000
int main()
{
	double sum = 0.0;
	for(int i = 1; i < INF; i++ )
	{
		for(int j = 1; j < INF; j++)
		{
			sum += pow(-1,i+j) / (i + j);
		}
	}
	cout << "Sum is : "<< sum <<  endl; // 0.193153,实际趋向值是：In2 - 1/2
	return 0;
}