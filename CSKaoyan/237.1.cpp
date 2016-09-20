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
// 返回指向生成链表的指针

// vector<int> ins;//test
List generateList(int n)
{
	srand((unsigned)time(NULL));
	// 先定义第一个结点

	int x = rand() % MAX;
	List L = (List)malloc(sizeof(Node));
	L->data = x;
	L->next = NULL;

	Node *temp = L; //使用temp拿着L的位置，为的是不改变L的数值

	//尾插法建立链表
	for(int i = 0; i < n; i++)
	{
		int x = rand() % MAX;
		Node *s = (Node*)malloc(sizeof(Node));
		s->data = x;
		s->next = NULL;

		// ins.push_back(x);
		temp->next = s; 
		temp = s;
	}
	return L;
}
//一次只删除一个x
void deleteElem(List &L,ElemType x)
{
	Node *p = L;
	//找到值为x的前驱结点
	while(p && p->next->data != x)
	{
		p = p->next;
	}
	Node *q = p->next;
	p->next = p->next->next;
	delete(q);
}

void deleteRec(List &L, ElemType x) // 通过引用传递操纵内存值，但是L的值不会因为L = L->next而改变！！
{
	Node *p = L;
	if(p == NULL)
	{
		return;
	}
	if(L->data == x)
	{
		p = L;
		L = L->next;
		delete(p);
		deleteRec(L,x);
	}
	else
	{
		deleteRec(L->next,x);
	}
}
int main()
{
	// 删除一个不带头结点的单链表L中所有值为x的结点
	int n;
	cout << "Input a number of nodes: " <<  endl;
	cin >> n;
	List L = generateList(n);//生成链表

	Node *p = L;
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

	// 先遍历找到x的个数
	p = L;
	int count = 0;
	while(p)
	{
		if(p->data == x)
		{
			count++;
		}
		p = p->next;
	}

	cout << "You want to delete " << count << " nodes" << endl;
	// for(int i = 0; i < count; i++)
	// {
	// 	deleteElem(L,x);
	// }
	deleteRec(L,x);
	

	//输出删除后的效果
	cout << L->data <<  endl;
	p = L; //复用p,反正p也闲着
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;

	p = L;
	while(p) //释放所有结点对应空间
	{
		delete(p);
		p = p->next;
	}
	return 0;
}