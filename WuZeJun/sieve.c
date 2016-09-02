#include<stdio.h>
#define MAX_N 1000
#define true 1
#define false 0
typedef int bool;
int prime[MAX_N];
bool is_prime[MAX_N + 1];

//返回n以内的素数的个数
int sieve(int n)
{
	int p = 0;
	for(int i = 0; i <= n; i++)
	{
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i <= n;i++)
	{
		if(is_prime[i])
		{
			prime[p++] = i;
			for(int j = 2 * i; j <= n;j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	//输出结果
	for(int i = 0; i < n; i++)
	{
		if(is_prime[i])
		{
			printf("%d ", prime[i]);
		}
	}
	return p;
}
int main(void)
{
	int n;
	printf("Input a number: \n");
	scanf("%d",&n);
	sieve(n);

	return 0;
}