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

void reverse(List &Head)
{
	//第一种想法：将后面的每一个结点插入到前面的结点前面即可
	//这是我的想法，调试了很多次才理顺

	Node *p = Head->next; //当前工作结点
	Node *after = p->next; //工作结点的后继结点
	p->next = NULL; //第一个工作结点的指针域将为空

	while(after)//后继结点还有值得时候
	{
		Node *temp = after->next;
		after->next = p;
		Head->next = after;

		//更新p和after的值，即：p指向after,after指向after后面的项
		p = after;
		after = temp;
	}
}

void reverse2(List &Head)
{
	// 答案提供了这个做法
	// 事实上更易想到
	List r;
	Node *p = Head->next;//工作指针
	Head->next = NULL;//头结点指针域设为空

	while(p)
	{
		r = p->next; //暂存p的后继
		p->next = Head->next;
		Head->next = p;
		p = r;
	}
}

int main()
{
	// 辅助空间为O(1)，就地逆置带头单链表

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


	p = Head->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	return 0;

}