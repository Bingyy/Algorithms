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
    struct Node *prior; // 前向指针
    struct Node *next; // 后向指针
}SNode, *SList;

// 生成一个循环双链表，数值随机生成
// 返回指向生成链表的头结点指针

SList generateSymList(int n) // n是结点个数
{
    srand((unsigned)time(NULL));
    // 定义头结点
    SList sl = (SList)malloc(sizeof(SNode));
    sl->prior = NULL;
    sl->next = NULL;
    
    SNode *r = sl;
    
    //尾插法建立链表
    for(int i = 0; i < n; i++)
    {
        SNode *s = (SNode*)malloc(sizeof(SNode));
        s->data = rand() % MAX; // 随机值
        s->prior = r;
        s->next = sl; //新的结点next域指向头结点，因为用r在跟踪当前工作结点，因此，这个结点的next域会更新为指向下一个结点
        
        r->next = s; // 这句就是在更新新结点的前驱的next域指向新结点
        sl->prior = s; //需要更新的是sl的prior，r跟踪是工作结点
        
        r = s; // r需要跟踪最新的结点，当前情况下，s无疑是最新的
    }
    return sl;
}


bool IsSymmetrical(SList sl) // sl是循环双链表的头结点
{
    SNode *p = sl->next; // 第一个结点
    SNode *q = sl->prior; // 最后一个结点
    
    while(p && q)
    {
        if(p == q || (p->next == q && q->prior == p && p->data == q->data))// 如果比较到p和q相等或者对称
        {
            return true;
        }
        else
        {
            if(p->data == q->data) // 只有数据相同时，才有机会进行下一次的比较
            {
                p = p->next;
                q = q->prior;
            }
            else // 否则直接判定不对称
            {
                return false;
            }
        }
    }
    return false;
}

int main()
{
    // 判断一个带头的循环双链表是否对称
    // 所以首先得构建一个循环双链表：主要是明晰结点的特征是有两个指针域
    // 单纯的双链表会有两个结点的指针域各空一个：头结点的prior指针域和尾结点的next指针域
    // 循环的话就是让头结点的prior指针域指向尾结点，尾结点的next指针指向头结点
    // 主要是如何构建，如果有奇数个结点，两个方向游走的指针相同时表示对称。
    // 偶数个结点，判断的是正向指针的next结点与反向指针的prior结点相同并且数值相同。
    // 正反向遍历时，结点值相同时才相向移动。否则，途中有不同的就退出，判断为不对称。
    
    int n;
    cout << "Input the number of nodes: ";
    cin >> n ;
    SList sl = generateSymList(n);
    
    // 正向输出
    SNode *p = sl->next; //指向第一个结点
    cout << "正向 : ";
    while(p != sl->prior)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data; //最后一个结点值需要特别输出
    
    cout << endl;
    
    // 反向输出
    p = sl->prior; //指向最后一个结点
    cout << "反向 : ";
    while(p != sl->next)
    {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << p->data; //第一个结点也需要特别输出
    cout << endl;
    
    // 题目的主要逻辑
    
    bool b = IsSymmetrical(sl);
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