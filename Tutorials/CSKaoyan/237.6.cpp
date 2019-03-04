#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;
typedef int ElemType;
#define MAX 100

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *List;

// 生成一个链表，数值随机生成
// 返回指向生成链表的头结点指针

List generateList(int n)
{
	srand((unsigned)time(NULL));
	// 定义头结点
	List Head = (List)malloc(sizeof(Node));
	Head->next = NULL;
	Node *temp = Head; //使用temp拿着L的位置，为的是不改变L的数值

	//尾插法建立链表
	for(int i = 0; i < n; i++)
	{
		int x = rand() % MAX;
		Node *s = (Node*)malloc(sizeof(Node));
		s->data = x;
		s->next = NULL;

		temp->next = s; 
		temp = s;
	}
	return Head;
}


void sortList(List &Head)
{
	//借助一个数组存储元素的值，然后再遍历链表重新赋值
	// 就是把排序的事情交给sort去做了

	vector<int> ins;
	Node *p = Head->next; //指向工作结点
	while(p)
	{
		ins.push_back(p->data);
		p = p->next;
	}

	sort(ins.begin(), ins.end()); // 使得ins中的数据递增有序

	p = Head->next;
	int i = 0;
	while(p)
	{
		p->data = ins[i];
		p = p->next;
		i++;
	}
}

// void sortListByHand(List &Head)
// {
// 	// 不是这样简单的，类似选择排序，需要不断与前面已经相排好序的再比较
// 	// 主要思路是，新建一个链表，每次扫描的结点与当前结点比较，如果较大，就插在工作结点后面，否则就在前面
// 	// 因此需要跟踪两个结点：当前工作结点和前驱结点
// 有待update -- 思路没理清

// 	Node *p = Head->next;
// 	Node *pre = Head;

// 	while(p)
// 	{
// 		Node *after = p->next; // p之后的结点

// 		if(after == NULL)
// 		{
// 			break;
// 		}

// 		if(p->data <= after->data) //否则就插到后面
// 		{
// 			pre = p;
// 			p = after;	
// 		}

// 		else if(p->data > after->data)//第二个结点值较小，插到前面
// 		{
// 			Node *temp = after->next; // 暂存after后的结点，after的链要更改
// 			after->next = p;
// 			pre->next = after;
// 			p->next = NULL;

// 			p = temp;
// 			pre = after;
// 		}
		
// 	} 
// }
int main()
{
	//设计算法使得带头节点的链表递增有序

	int n;
	cout << "Input a number of nodes: ";
	cin >> n;
	List Head = generateList(n);

	Node *p = Head->next; //指向第一个结点
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	//写题目的主要逻辑

	sortList(Head);
	// sortListByHand(Head);

	p = Head->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;

	return 0;

}