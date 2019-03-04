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

List getCommonElements(List A, List B) //不能修改A和B的值
{
    // 主要思路很简单：用p和q跟踪当前工作结点
    // 如果p和q的值相等，就把它插到C中，使用尾插法, 然后p和q同时后移动
    // 否则，如果p的值较小p后移，反之亦然

    // 这个算法的设计会如果两个链表同时有同样的元素多个，则多个都会保留，不会去重
    // 如果只有一方有多个相同的值，另一方只有一个，则只会保留一个
    // 这符合我们的预期
    
    Node *p = A->next; // 跟踪当前A工作结点
    Node *q = B->next; // 跟踪当前B工作结点
    // 构建单链表C
    List C = (List)malloc(sizeof(Node));
    C->next = NULL;
    Node *r = C; //r虽然指向的是C的末尾结点，初始也是等于C，这个头结点， 如果脑洞打开令 r = C->next; 会有内存问题
    
    while(p && q)
    {
        if(p->data < q->data)
        {
            p = p->next;
        }
        else if(q->data < p->data)
        {
            q = q->next;
        }
        
        else // p->data == q->data
        {
            Node *s = (Node*)malloc(sizeof(Node));
            s->next = NULL;
            // 尾插法
            s->data = p->data;
            r->next = s; // r指向的C的尾结点
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    // r->next = NULL; // 这个不需要，因为在else中每个新建的结点的next域都定义为NULL了
    return C;
}

int main()
{
    // 两个递增的单链表 A, B
    // 从A和B的公共元素产生一个单链表C
    // 不要破坏A和B的结点
    // 即：只用一下元素值，C的结点重新构建
    
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
    
    List C = getCommonElements(A,B); // 返回新建的链表的头结点
    
    // 输出公共元素C
    
    p = C->next;
    cout  << "The common elements : ";
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    
    return 0;
    
}