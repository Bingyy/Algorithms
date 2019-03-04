#include <iostream>
#include <ctime>
#include <vector>


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
	// 删除带头结点的单链表L的最小值结点的高效算法

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

	//第一次遍历寻找这个最小值
	p = Head->next;
	int min = p->data;
	while(p)
	{
		
		if(p->data < min)
		{
			min = p->data;
		}
		p = p->next;
	}

	cout << min << endl;

	p = Head->next;
	Node *pre = Head; //双指针,pre用于记录当前游走的结点的前驱

	//第二次遍历删除这个唯一的最小值
	while(p)
	{
		if(p->data == min)
		{
			Node *q = p;
			pre->next = p->next;
			delete(q);
		}
		pre = pre->next; //pre总是比p慢一拍
		p = p->next;
	}

	p = Head->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;

}