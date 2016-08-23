#define INF 10000000
#define MAX 400
#include<stdio.h>

//邻接矩阵表示图
typedef struct _graph
{
	char vexs[MAX];
	int vexnum;
	int edgenum;
	int matrix[MAX][MAX];
} Graph, *PGraph;

//边的关系表示
typedef struct _EdgeData
{
	char start;
	char end;
	int weight;
};

void dijkstra(Graph G, ){

}

int main(){
	return 0;
}