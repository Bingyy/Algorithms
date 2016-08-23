//邻接表形式的图的定义
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

ADT Graph{
	数据对象V：V具有相同特性的数据元素的集合，称为顶点集
	数据关系R:
		R = {VR}
		VR = {<v,w> | v,w belong to V且P(v,w),<v,w>表示从v到w的弧，谓词P(v,w)定义了弧的意义或者信息}

	基本操作P:
	void CreateGraph(&G,V,VR){
		//初始条件：V是图的顶点集，VR是图中弧的集合
		//操作结果：按照V,VR定义构造图
	}

	void DestroyGraph(&G){
		//初始条件：图G存在
		// 操作结果：销毁图
	}
	int LocateVex(G,u){
		// 初始条件：图G存在，u和G中有相同的特征的顶点
		// 操作结果：若G中存在顶点u，则返回顶点在图中位置，否则返回其他信息
	}
	int GetVex(G,v){
		// 初始条件：图G存在，v是G中某个顶点
		// 操作结果：返回v的值
	}
	void PutVex(&G,v,value){
		// 初始条件：图G存在，v是G中某个顶点
		// 操作结果：对v赋值value
	}
	Node * FirstAdjVex(G,v){
		// 初始条件：图G存在，v是G中某个顶点
		// 操作结果：返回v的第一个邻接顶点，若顶点在G中没有邻接顶点，则返回空
	}
	Node * NextAdjVex(G,v,w){
		// 初始条件：图G存在，v是G中某个顶点,w是v的邻接顶点
		// 操作结果：返回v的（相对于w）下一个邻接顶点，若w是v的最后一个邻接点，则返回空
	}
	void InsertVex(&G,v){
		// 初始条件：图G存在，v和G中顶点有相同特征
		// 操作结果：在图中增添新结点v
	}

	void DeleteVex(&G,v){
		// 初始条件：图G存在，v是G中某个顶点
		// 操作结果：在图中删除结点v
	}
	void InsertArc(&G,v,w){
		// 初始条件：图G存在，v,w是G中两个顶点
		// 操作结果：在图中增加弧<v,w>,若G是无向的，还增加对称弧
	}
	void DeleteArc(&G,v,w){
		// 初始条件：图G存在，v,w是G中两个顶点
		// 操作结果：在图中删除弧<v,w>,若G是无向的，还删除对称弧
	}

	void DFSTraverse(G,Visit()){
		// 初始条件：图G存在，Visit是顶点的应用函数
		// 操作结果：对图进行深度优先遍历，每个顶点Visit()一次，一旦Visit失败，则操作失败
	}
	void BFSTraverse(G,Visit()){
		// 初始条件：图G存在，Visit是顶点的应用函数
		// 操作结果：对图进行宽度优先遍历，每个顶点Visit()一次，一旦Visit失败，则操作失败
	}
}ADT Graph;