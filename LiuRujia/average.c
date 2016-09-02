#include<stdio.h>
int main()
{
	int *num;
	int *p;
	int sum = 0;
	for(int i = 0; i < 3; i++)
	{

		scanf("%d",&num[i]);
	}
	for(int i = 0; i < 3; i++)
	{
		sum += num[i];
	}
	printf("%.3lf\n",sum / 3.0);
	return 0;
}
