#include<stdio.h>
#define MAX_N 20
typedef int bool;
#define true 1
#define false 0
int a[MAX_N];
int k;

bool dfs(int i, int sum)
{
	if(i == sum) return sum == k;
	return false;
}

int main()
{
	printf(1==1);
	return 0;
}