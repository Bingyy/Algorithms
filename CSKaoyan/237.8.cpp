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

List generateList1(int n)
{
	srand((unsigned)time(NULL));
	// 定义头结点
	List Head = (List)malloc(sizeof(Node));
	Head->next = NULL;
	Node *temp = Head; //使用temp拿着L的位置，为的是不改变L的数值

	//尾插法建立链表
	// for(int i = 0; i < n; i++)
	// {
	// 	int x = rand() % MAX;
	// 	Node *s = (Node*)malloc(sizeof(Node));
	// 	s->data = x;
	// 	s->next = NULL;

	// 	temp->next = s; 
	// 	temp = s;
	// }

		Node *s = (Node*)malloc(sizeof(Node));
		s->data = 1;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 2;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 3;
		s->next = NULL;
		temp->next = s; 
		temp = s;


		s = (Node*)malloc(sizeof(Node));
		s->data = 7;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 8;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 9;
		s->next = NULL;
		temp->next = s; 
		temp = s;

	return Head;
}

List generateList2(int n)
{
	srand((unsigned)time(NULL));
	// 定义头结点
	List Head = (List)malloc(sizeof(Node));
	Head->next = NULL;
	Node *temp = Head; //使用temp拿着L的位置，为的是不改变L的数值

	//尾插法建立链表
	// for(int i = 0; i < n; i++)
	// {
	// 	int x = rand() % MAX;
	// 	Node *s = (Node*)malloc(sizeof(Node));
	// 	s->data = x;
	// 	s->next = NULL;

	// 	temp->next = s; 
	// 	temp = s;
	// }

		Node *s = (Node*)malloc(sizeof(Node));
		s->data = 5;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 6;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 7;
		s->next = NULL;
		temp->next = s; 
		temp = s;


		s = (Node*)malloc(sizeof(Node));
		s->data = 8;
		s->next = NULL;
		temp->next = s; 
		temp = s;

		s = (Node*)malloc(sizeof(Node));
		s->data = 9;
		s->next = NULL;
		temp->next = s; 
		temp = s;

	return Head;
}

Node * findCommonNodes(List H1, List H2)
{
	int s1 = 0, s2 = 0; //表示两个链表的尺寸
	Node *p = H1->next;
	Node *q = H2->next;
	while(p)
	{
		s1++;
		p = p->next;
	}

	while(q)
	{
		s2++;
		q = q->next;
	}

	p = H1->next;
	q = H2->next; //归位

	// 长的先走
	if(s1 >= s2)
	{
		int r = s1 - s2;
		for(int i = 0;i < r; i++)
		{
			p = p->next;
		}
	}
	if(s1 < s2)
	{
		int r = s2 - s1;
		for(int i = 0;i < r; i++)
		{
			q = q->next;
		}
	}

	// 开始一起走
	while(p && q)
	{
		if(p->data == q->data)
		{
			return p;
		}
		else 
		{
			p = p->next; 
			q = q->next;
		}
	}
	return NULL;

}

int main()
{
	// 给定两个单链表，寻找两个单链表的公共结点
	// 也即，结点的地址相同
	// 这里需要考虑到，一旦第一个相同的结点出现，那么后面的结点一定全部相同
	// 所以考虑采用尺量法：将末尾对齐，让长的那个链表先走一段尺寸的差值，
	// 然后开始一起走，比较结果值是否相同，如相同，那么公共结点就找到了

	int n,m;
	cout << "Input two numbers of two lists: ";
	cin >> n >> m;
	List H1 = generateList1(n);
	List H2 = generateList2(m);

	Node *p = H1->next; //指向第一个结点
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	p = H2->next; //指向第一个结点
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;


	//写题目的主要逻辑

	Node *res= findCommonNodes(H1,H2);

	while(res)
	{
		cout << res->data << " ";
		res = res->next;
	}

	cout << endl;
	return 0;

}