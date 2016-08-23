/***************************
有向图的Dijkstra的算法实现
*********************/


#include<iostream>
using namespace std;
const int maxnum = 100;
const int maxint = 999999;

void Dijkstra(int n, int v, int *dist,int *prev, int c[maxnum][maxnum]){
	bool s[maxnum]; //判断是否已经存入该点到集合S中
	for(int i = 1; i <= n; i++){
		dist[i] = c[v][i];
		s[i] = 0; //初始都未使用过该点
		if(dist[i] == maxint){
			prev[i] = 0;
		}
		else{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = 1;
	//依次将未放入S集合的顶点中，取dist[i]最小值的结点，放入集合S中
	//一旦集合S包含了所有V中顶点，dist就记录了从源点到其他所有顶点之间的最短路径
	for(int i = 2; i <= n; i++){
		int temp = maxint;
		int u = v;
		//找出当前未使用的点j的dist[j]的最小值
		for(int j = 1; j <= n; j++){
			if(!s[j] && dist[j] < temp){
				u = j;//u保存当前邻接点中距离最小的点的号码
				temp = dist[j];
			}
		}
		
		s[u] = 1;//表示u点已经存入集合S

		//更新dist
		for(int j = 1;j <= n; j++){
			if(!s[j] && c[u][j] < maxint){
				int newdist = dist[u] + c[u][j];
				if(newdist < dist[j]){
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}


void searchPath(int *prev, int v, int u){
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int temp = prev[u];
	while(temp != v){
		que[tot] = temp;
		tot++;
		temp = prev[temp];
	}
	que[tot] = v;
	for(int i = tot; i >= 1; i--){
		if(i != 1){
			cout << que[i] << "->";
		}
		else{
			cout << que[i] << endl;
		} 
	}
}

int main(){
	freopen("input.txt","r", stdin);

	//数组下标从1开始
	int dist[maxnum]; //表示当前点到源点的最短路径长度
	int prev[maxnum]; //记录当前点的前一个结点
	int c[maxnum][maxnum]; //记录图的两点间的路径长度
	int n, line;//图的结点数和路径数

	cin >> n;
	cin>>line;
	int p, q, len;//输入p,q两点及其路径长度

	//初始化c[][]为maxint,就是无穷大的意思
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			c[i][j] = maxint;
		}
	}
	for(int i = 1;i <= line; i++){
		cin >> p >> q >> len;
		if(len < c[p][q]){//有重边
			c[p][q] = len;//p -->q
			c[q][p] = len; // q-->p
		}
	}

	for(int i = 1; i <=n; i++){
		dist[i] = maxint;
	}
	for(int i = 1; i <=n;i++){
		for(int j = 1; j <= n; j++){
			printf("%8d", c[i][j]);
		}
		printf("\n");
	}
	Dijkstra(n,1,dist,prev,c);

	//最短路径长度
	cout << "源点到最后一个顶点的最短路径长度是： "<< dist[n] << endl;

	//路径
	cout << "源点到最后一个顶点的路径为： ";
	searchPath(prev,1,n);

}