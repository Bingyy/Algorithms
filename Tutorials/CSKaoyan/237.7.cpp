#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;
typedef int ElemType;
#define MAX 100
#define bool int
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

bool isInRange(int ra, int rb, int target)
{
	if((target >= ra) && (target <= rb))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void deleteRange(List &Head, int ra, int rb)
{
	// 主要思路：遍历单链表，如果在这个范围就删掉
	// 需要跟踪两个结点：当前与前驱

	Node *pre = Head;
	Node *p = Head->next;

	while(p)
	{
		if(isInRange(ra,rb,p->data))
		{
			// 在范围内，需要删除,此时前驱结点pre本身的值不用更新 ，更新的是其指针域
			Node *temp = p;
			pre->next = p->next;
			delete(temp);
			p = p->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

int main()
{
	// 带头结点的无序单链表
	// 删除表中介于两个值之间的元素，如果存在的话

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

	int ra, rb;
	cout << "Input ra and rb(ra < rb): ";
	cin >> ra >> rb;
	//写题目的主要逻辑
	deleteRange(Head,ra,rb);


	p = Head->next;
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;

	return 0;

}