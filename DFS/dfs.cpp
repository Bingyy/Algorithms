#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;
#define MAX_VERTEX_NUM 10
struct Node
{
	int adjvex;
	struct Node *next;
	int info;
};

typedef struct VNode
{
	char data;
	Node *first;
}VNode, AdjList[MAX_VERTEX_NUM];

struct Graph
{
	AdjList vertices;//存储VNode类型元素数组
	int vexnum, arcnum;//顶点数目，边数目
};

int visited[MAX_VERTEX_NUM];//记录已经访问过的结点

int locateVex(Graph G, char u){
	int i;
	//遍历顶点数组，查找匹配元素
	for(i = 0; i < G.vexnum; i++){
		if(u == G.vertices[i].data){
			return i;
		}
	}
	if(i == G.vexnum){
		printf("Error u\n");
		exit(1);
	}
	return 0;
}
//创建图
void CreateGraph(Graph &G){
	int i, j, k, w;
	char v1,v2,enter;

	Node *p;
	printf("input vexnum & arcnum: \n");
	scanf("%d",&G.vexnum);
	scanf("%d",&G.arcnum);

	printf("input vertices:\n");
	for(i = 0; i < G.vexnum; i++){
		scanf("%c%c",&enter,&G.vertices[i].data);
		G.vertices[i].first = NULL;
	}

	printf("input arcs(v1,v2,w):\n");
	for(k = 0; k < G.arcnum; k++){
		scanf("%c%c",&enter, &v1);
		scanf("%c%c",&enter,&v2);
		scanf("%d",&w);
		i = locateVex(G,v1);
		j = locateVex(G,v2);
		p = (Node *)malloc(sizeof(Node));
		p->adjvex = j;
		p->info = w;
		p->next = G.vertices[i].first;
		G.vertices[i].first = p;
	}
}



void DFS(Graph &G, int v){
	Node *p;
	printf("%c",G.vertices[v].data);
	visited[v] = 1;
	p = G.vertices[v].first;

	while(p){
		//如果相邻的没有被访问,递归
		if(!visited[p->adjvex]){
			DFS(G,p->adjvex);
			p = p->next;
		}
	}
}
//遍历全部结点
void DFSTranverse(Graph &G){
	for(int v = 0; v < G.vexnum; v++){
		visited[v] = 0;
	}
	for(int v = 0; v < G.vexnum; v++){
		if(!visited[v]){
			DFS(G,v);
		}
	}
}

int main(){
	Graph G;
	CreateGraph(G);
	DFSTranverse(G);
	return 0;
}
