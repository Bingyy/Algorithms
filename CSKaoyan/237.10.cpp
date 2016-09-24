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


int main()
{
    // 将一个单链表拆分为两个带头结点的单链表，其中表1含有奇数下标的元素，表2含有偶数下标的元素
    // 保持相对顺序不变

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
    List A = Head;
    List B = (List)malloc(sizeof(Node));
    B->next = NULL;

    // 顺序游走原单链表
    p = Head->next;
    Node *pa = A;
    Node *pb = B;

    int i = 0;
    while(p)
    {
        i++;
        if(i % 2 == 0) //如果当前是偶数那么就插在pb上
        {
            pb->next = p;
            pb = p;
        }
        else // 否则就插在pa上
        {
            pa->next = p;
            pa = p;
        }
        p = p->next;
    }

    pa->next = NULL;
    pb->next = NULL; 

    cout << "A" << endl;
    p = A->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;

    cout << "B" << endl;
    p = B->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;

    return 0;

}