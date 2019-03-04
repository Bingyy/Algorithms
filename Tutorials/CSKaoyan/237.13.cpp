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
    srand(n);
    // 定义头结点
    List Head = (List)malloc(sizeof(Node));
    Head->next = NULL;
    Node *temp = Head; //使用temp拿着L的位置，为的是不改变L的数值

    // 先通过vector建立一个递增有序的数列
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
        Node *s = (Node*)malloc(sizeof(Node));
        s->data = ins[i];
        s->next = NULL;

        temp->next = s; 
        temp = s;
    }
    return Head;
}
void mergeList(List &H1, List &H2)
{
    // 两个递增 ==》 一个递减
    // 思路：采用头插法进行
    // 用两个指针p,q分别跟踪
    // 如果p指向的结点较小，就插入并将p往后移动，否则将q插入并移动
    // 当一方结点为空了，就将对方的结点依次头插法插入链表直到结束
    List m = (List)malloc(sizeof(Node));
    m->next = NULL;
    Node *p = H1->next;
    Node *q = H2->next;

    while(p && q)
    {
        if(p->data <= q->data)
        {
            Node *temp = p->next;// 暂存
            p->next = m->next;
            m->next = p;
            p = temp;
        }
        else
        {
            Node *temp = q->next;
            q->next = m->next;
            m->next = q;
            q = temp;
        }
    }

    while(p)
    {
        Node *temp = p->next; // 注意一定要用temp暂存，总是会不注意p->next 已经被更改了，从而陷入死循环
        p->next = m->next;
        m->next = p;
        p = temp;
    }
    while(q)
    {
        Node *temp = q->next;
        q->next = m->next;
        m->next  = q;
        q = temp;
    }

    H1 = m;
}
int main()
{
    // 两个递增的单链表
    // 合并成一个递减的单链表
    // 且为了节省空间，只是修改链接


    int n,m;
    cout << "Input two numbers of nodes: ";
    cin >> n >> m;
    List H1 = generateList(n);
    List H2 = generateList(m);

    Node *p = H1->next; //指向第一个结点
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    Node *q = H2->next; //指向第一个结点
    while(q)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
    // 题目的主要逻辑

    mergeList(H1,H2); // 返回的是H1指向的合并好的链表

    // 输出合并后的结果
    p = H1->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    return 0;

}