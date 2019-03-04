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

List DisCreate(List &A)
{
    List B = (List)malloc(sizeof(Node)); // B链表表头
    B->next = NULL;

    Node *p = A->next, *q; // A的工作指针
    Node *ra = A; 

    while(p) // 这是一个很自然的流程，慢慢体会
    {
        ra->next = p; //ra的next直接连接p
        ra = p; // ra游走到p，新加入的结点上
        p = p->next; // p游走到下一个结点
        q = p->next; // q暂存p的下一个结点

        p->next = B->next; // 头插法，所以p当前指向的结点
        B->next = p; // B指向p
        p = q; // 现在更新p为q暂存的那个结点值
    }
    ra->next = NULL;
    return B;
}



int main()
{
    // C = {a1,b1,a2,b2,...,an,bn}为线性表
    // 就地算法，将其拆分为两个线性表
    // A = {a1,a2,a3,...,an}
    // B = {b1,b2,b3,...,bn}


    int n;
    cout << "Input a number of nodes: ";
    cin >> n;
    List hc = generateList(n);

    Node *p = hc->next; //指向第一个结点
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    // 题目的主要逻辑

    List B = DisCreate(hc);

    p = hc->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;

    Node *q = B->next;

    while(q)
    {
        cout << q->data << " ";
        q = q->next;
    }

    cout << endl;
    return 0;

}