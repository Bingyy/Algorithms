#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#include <algorithm>
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
    //for test
    for(int i = 0; i < ins.size() / 2 ; i++)
    {
        ins.push_back(ins[3]);
    }
    // sort(ins.begin(), ins.end());//有序
    return ins;
}

// 寻找主元素：超过半数的元素称之为主元素

int main()
{
    vector<int> ins;
    // ins = {0,5,5,3,5,7,5,5}; //共8个元素，有5个5，所以5是主元素
    ins = generateVector();

    for(auto it = ins.begin();it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout  <<  endl;

    vector<int> counts;
    //一种比较懒的做法是：使用count统计每个数据出现的次数，选择这个数据就好了
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        int tmp = count(ins.begin(), ins.end(), *it);
        counts.push_back(tmp);
    }
    int max = counts[0];
    int index;
    for(int i = 1; i < counts.size(); i++)
    {
        if(max < counts[i])
        {
            max = counts[i];
            index = i;
        }
    }
    if(max > ins.size() / 2)
    {
        cout << "Got it! " << ins[index] << endl;
    }
    else
    {
        cout << "No such element!" << endl;
    }
    return 0;
}
