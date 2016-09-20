#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
const int MAX = 100;
using namespace std;

// time : 2016-9-15 --中秋节
// author : Wang Bing

//抽出一个生成vector函数
vector<int> generateVector()
{
    vector<int> ins;//初始啥也没有
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    // sort(ins.begin(), ins.end());//有序
    return ins;
}

// 时间和空间均高效的算法
// 将数组中的序列循环左移p个位置 (0 < p < n)

// 设计：基于队列的实现方法
// 将前p个元素进队列，再依次出队列

// 这是一个时间复杂度和空间复杂度均为O(n)的算法

// 还有更优秀的空间复杂度仅为O(1)的递归算法
// 我目前还没掌握
// 本例的算法实现，很自然易懂
int main()
{
    vector<int> ins = generateVector();
    queue<int> inq;

    for(auto it = ins.begin();it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout  <<  endl;

    for(auto it = ins.begin();it != ins.end(); it++)
    {
        inq.push(*it); //数据依次进入队列
    }

    cout << "Input a number you want to shift left: ";
    int p;
    cin >> p;
    // 再一次进队，出队即可
    for(int i = 0; i < p; i++)
    {
        int tmp = inq.front();
        inq.pop();
        inq.push(tmp);
    }

    // 再将数据回填到vector
    for(int i = 0; i < ins.size(); i++)
    {
        int tmp = inq.front();
        ins[i] = tmp;
        inq.pop();
    }

    for(auto it = ins.begin();it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout  <<  endl;

    return 0;
}
