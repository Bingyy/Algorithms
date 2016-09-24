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

void unionList(List &A, List &B) // 要对A，B的结点进行操作，所以传递引用
{
    // 主要思路：仍是归并的想法，只不过归并算法中是将每个元素都归并起来，这里加个条件，只保存相同的元素
    Node *pa = A->next;
    Node *pb = B->next;
    Node *r = A;
    Node *temp; // 用于释放结点
    while(pa && pb)
    {
        if(pa->data < pb->data)
        {
            temp = pa;
            pa = pa->next;
            delete(temp);
        }
        else if(pb->data < pa->data)
        {
            temp = pb;
            pb = pb->next;
            delete(temp);
        }
        else
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
            pb = pb->next;
        }
    } // end of while

    // 到这里还要继续释放较长的链表的剩余结点
    while(pa)
    {
        temp = pa;
        pa = pa->next;
        delete(temp);
    }

    while(pb)
    {
        temp = pb;
        pb = pb->next;
        delete(temp);
    }

    r->next = NULL; // 不可忘了最后一个结点的指针域要为空
    delete(B); // 最好是连B的头也释放掉，即：最后斩首B链表
}

int main()
{
    // 两个递增的单链表 A, B
    // 找到交集的元素存到A中，不用的结点请释放掉
    
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
    
    unionList(A,B);
    
    p = A->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    
    return 0;
    
}