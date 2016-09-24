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
    
    // 先通过vector建立一个递增有序的数列
    vector<int> ins;
    for(int i = 0; i < n; i++)
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    
    sort(ins.begin(), ins.end());
    
    //尾插法建立链表：元素递增有序
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

bool isBSubPatternOfA(List A,List B)
{
    // 主要思路是简单的暴力搜索法：A从第一个结点开始与B比较，如果相同就同步后移
    // 如果到后面有不匹配的情况，就从A上一次比较的结点的下一个开始比较
    // B从头开始
    Node *p = A->next;
    Node *q = B->next;
    Node *pre = p; // 初始值这么写比 pre = A->next更有意义，当然这个不是很重要，只是可读性强些

    while(p && q)
    {
        if(p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else 
        {
            pre = pre->next;
            p = pre;
            q = B->next; // 注意有头结点与无头结点的区别
        }
    } // end of while

    // 判断何时是子序列
    if(q == NULL) // q能走到底表示B是子序列
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    // 两个整数数列存入了两个单链表A,B，判断B是否为A的连续子序列

    int n,m;
    cout << "Input two numbers of nodes: ";
    cin >> n >> m;
    List A = generateList(n);
    List B = generateList(m);
    
    Node *p = A->next; //指向第一个结点
    cout << "A : "; 
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    
    Node *q = B->next; //指向第一个结点
    cout << "B : ";
    while(q)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;


    // 题目的主要逻辑
    bool b = isBSubPatternOfA(A,B);
    cout << b << endl;
    if(b)
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }
    return 0;
    
}