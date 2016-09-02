#include<stdio.h>
#include<string.h>
//Not passed
int pre[30001];

int find(int x)
{
	int r = x;
	while(r != pre[r])//直到自己是自己的老大为止
		r = pre[r];
	//路径压缩
	int i = x, j;
	while(r != pre[i]) //如果i的老大不是掌门人
	{
		j = pre[i]; //暂时存储一下i的老大
		pre[i] = r; //更改i的老大为直接掌门人
		i = j; //再去搞i的曾经的老大
	}
	return r;
}

void join(int x, int y)//让x和y做朋友
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fy] = fx;
}

int main()
{
	int N,M;//N表示结点数，M表示群组数
	int k; //每个群组中的结点数
	int x, y;
	int ans = 0;

	while(scanf("%d%d",&N,&M)) //如果读入的N为0结束
 	{
 		ans = 0;
 		if(M == N && N == 0) break;
 		if(M == 0) 
 		{
 			printf("1\n");
 			continue;
 		}
		for(int i = 0; i < N; i++)//初始化，每个人是自己的老大
			pre[i] = i;
		for(int i = 0; i < M; i++)
		{
			//吸收并整理数据
			scanf("%d",&k);
			scanf("%d",&x);
			for(int j = 1; j < k;j++)
			{
				scanf("%d",&y);
                if(pre[x] == 0)
                    pre[y] = 0;
				join(x,y);
                if(pre[y] == 0)
                    pre[x] = 0;
                
                if(pre[x] == 0)
                    pre[y] = 0;
				x = y;
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(pre[i] == 0)
				++ans;
		}

		printf("%d\n",ans);
	}
	return 0;
}