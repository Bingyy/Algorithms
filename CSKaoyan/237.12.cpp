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

    // 先通过vector建立一个有序的数列
    vector<int> ins;
    for(int i = 0; i < n; i++)
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }

    sort(ins.begin(), ins.end()); 

    //尾插法建立链表
    for(int i = 0; i < n; i++)
    {
        int x = rand() % MAX;
        Node *s = (Node*)malloc(sizeof(Node));
        s->data = ins[i];
        s->next = NULL;

        temp->next = s; 
        temp = s;
    }
    return Head;
}

void uniqueList(List &Head)
{
    // 主要思路：因为是递增有序，所以只需顺序游走即可
    // 每个相同的值仅仅保留一个，其他的结点删除

    Node *p = Head->next;
    Node *pre = Head; // 仍然跟踪前驱
    while(p)
    {
        if(p->data != pre->data)
        {
            pre->next = p;
            pre  = p;
            p = p->next;
        }
        else
        {
            Node *q = p;
            delete(q);
            p = p->next; //此时不用更新pre
        }
    }
}
int main()
{
    // 在一个递增有序的线性表中，存在数值相同的元素
    // 存储方式是单链表
    // 去掉数值相同的元素

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

    // 题目的主要逻辑

    uniqueList(Head);


    p = Head->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;

    return 0;

}