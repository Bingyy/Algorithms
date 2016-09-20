#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

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


int main()
{
	// L是带头结点的单链表，反向输出每个结点的值
	// 首先想到的是用栈存储一次遍历的值然后对栈进行操作即可
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

	//int栈，也可以用vector存，反向输出即可
	stack<int> nodes;

	p = Head->next;
	while(p != NULL)
	{
		nodes.push(p->data);
		p = p->next;
	}

	while(!nodes.empty())
	{
		// int tmp = nodes.top();
		cout << nodes.top() << " ";
		nodes.pop();
	}

	cout << endl;
	return 0;
}