#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
int max(int a, int b, int c);
int main(void)
{
	/* code */
	int n,a[100];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	int count = 0;
	//判断是是否可以组成三角形:穷举两个条件
	//1)两边之和大于第三边
	//2）两边之差小于第三边
	// for(int i = 0; i < n;i++)
	// {
	// 	for(int j = 0;j < n && j != i; j++)
	// 	{
	// 		for(int k = 0; k < n && k != i && k != j; k++)
	// 		{
	// 			if((a[i] + a[j] > a[k]) && (a[i] + a[k] > a[j]) && (a[k] + a[j] > a[i]) && (abs(a[i] - a[j]) < a[k]) &&(abs(a[i] - a[k]) < a[j]) && (abs(a[k] - a[j]) < a[i]))
	// 			{
					// printf("%d %d %d can compose a triangle!\n", a[i],a[j],a[k]);
	// 				count++;
	// 			}
	// 		}
	// 	}
	// }

	//更简洁的算法是：最长棍子的长度小于其余两根棍子之和（充要条件）
	// 假设 c > a >b
	//c < a + b ==>c - a < b && c - b < a,并且c最大，所以c + a > b, c + b > a
	//三角形的条件全部满足
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n && j != i; j++)
		{
			for(int k = 0; k < n && k != i && k != j; k++)
			{
				int edgeMax = max(a[i],a[j],a[k]);
				int len = a[i] + a[j] + a[k];
				if(edgeMax < len - edgeMax){
					printf("%d %d %d can compose a triangle!\n", a[i],a[j],a[k]);
					printf("The perimeter is %d\n",len);
					count++;
				}
			}
		}
	}

	if(count == 0)
	{
		printf("No triangle can be composed by those numbers!\n");
	}
	return 0;
}
int max(int a, int b, int c)
{
	int max;
	if(a > b && a > c){
		max = a;
	} 
	else if(b > a && b > c){
		max = b;
	}
	else 
	{
		max = c;
	}
	return max;
}