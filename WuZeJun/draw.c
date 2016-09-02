#include<stdio.h>
#define MAX 50
int main(void)
{
	/* code */
	int n,m,arr[MAX];
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				for(int l = 0; l < n;l++)
				{
					if((arr[i] + arr[j] + arr[k] + arr[l]) == m)
						printf("Yes!%d + %d + %d + %d = %d\n",arr[i],arr[j],arr[k],arr[l],m);
				}
			}
		}
	}
	return 0;
}