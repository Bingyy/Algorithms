#include<stdio.h>
#define INF 100000000
#define MAX 400
//邻接矩阵
typedef struct _graph
{
	char vexs[MAX];//顶点集合
	int vexnum; //顶点数
	int edgenum; //边数
	int matrix[MAX][MAX];//邻接矩阵，表达顶点之间关系
}Graph,*PGraph;

//边的结构体
typedef struct _EdgeData
{
	char start;//边的起点
	char end;//边的终点
	int weight;//边的权重
}EData;

/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 * 	G-- 图
 *	vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *	prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *	dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */

void dijkstra(Graph G,int vs, int prev[], int dist[]){
	int i, j,k;
	int min;
	int tmp;
	int flag[MAX];//flag[i] = 1表示顶点vs到顶点i的最短路径已经成功获取

	//初始化
	for(i = 0; i < G.vexnum; i++){
		flag[i] = 0;//顶点i的最短路径还没获取到
		prev[i] = 0; //顶点i的前驱顶点为0
		dist[i] = G.matrix[vs][i]; //顶点vs到顶点i的权
	}

	//对顶点vs自身进行初始化
	flag[vs] = 1;
	dist[vs] = 0;

	//遍历G.vexnum - 1次，每次找出一个顶点的最短路径
	for(i = 1; i < G.vexnum; i++){
		//寻找当前最小的路径：在未获取最短路径的顶点中，找到离vs最近的顶点（k）
		//这个算法没有U数组，需要每次循环G.vexnum次寻找合适的k
		min = INF;
		for(j = 0; j < G.vexnum; j++){
			if(flag[j] == 0&& dist[j] < min){
				min = dist[j];
				k = j;
			}
		}

		//标记“顶点k”为已经获取到最短路径
		flag[k] = 1;

		//修正当前最短路径和前驱结点
		//即：新成员加入后，需要更新dist和prev数组
		for(j = 0; j < G.vexnum; j++){
			tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j]));
			if(flag[j] == 0 && (tmp < dist[j])){
				dist[j] = tmp;
				prev[j] = k;
			}
		}
	}
	//打印最短路径的结果
	printf("dijkstra(%c): \n", G.vexs[vs]);
	for(i = 0; i < G.vexnum; i++){
		printf(" shortest(%c, %c)=%d\n",G.vexs[vs],G.vexs[i],dist[i]);
	}
}

int main(){

	return 0;
}
