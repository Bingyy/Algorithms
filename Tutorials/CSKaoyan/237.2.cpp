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

// vector<int> ins;//test
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
		s->data = 10;
		s->next = NULL;

		temp->next = s; 
		temp = s;
	}
	return Head;
}
//一次只删除一个x
void deleteElem(List &Head,ElemType x)
{
	//用双指针的方式，跟踪当前指向结点和前驱结点
	Node *pre = Head;
	Node *cur = Head->next;

	//找到值为x的前驱结点
	while(cur != NULL)
	{
		if(cur->data == x)
		{
			Node *q = cur;
			delete(q);
			pre->next = cur->next;
			cur = cur->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}

int main()
{
	// 删除一个带头结点的单链表L中所有值为x的结点，假设x的值不唯一
	int n;
	cout << "Input a number of nodes: " <<  endl;
	cin >> n;
	List Head = generateList(n);//生成链表,返回的是头结点指针

	Node *p = Head->next; //指向第一个结点
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	// 开始执行主要逻辑
	ElemType x;
	cout << "Input the number you want to delete: ";
	cin >> x;

	deleteElem(Head,x);

	p = Head->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	cout << endl;

	while(Head) //删除全部结点空间
	{
		delete(Head);
		Head = Head->next;
	}

	return 0;
}