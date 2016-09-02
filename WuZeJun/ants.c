//理解了这个算法，这个问题就变得非常容易解决了
//只需要每只蚂蚁走的路程最短或者最长，时间就是最长的了
#define MAX_N 1000000
#define max(a,b)(a>b?a:b)
 #define min(a,b)(a<b?a:b)
#include<stdio.h>
int L, n;
int x[MAX_N];
void solve()
{
	//最短时间
	int minT;
	for(int i = 0; i < n; i++)
	{
		minT = max(minT,min(x[i],L-x[i]));
	}
	//最长时间
	int maxT;
	for(int i = 0; i < n; i++)
	{
		maxT = max(maxT,max(x[i],L-x[i]));
	}
	printf("%d %d\n",minT,maxT);
}

int main()
{
	scanf("%d%d",&L,&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&x[i]);
	}
	solve();

	return 0;
}