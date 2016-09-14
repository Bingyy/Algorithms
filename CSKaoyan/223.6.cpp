#include <iostream>
#include <vector>
#include <ctime>
const int MAX = 100;
using namespace std;

//抽出一个生成vector函数：生成的数据不重复
vector<int> generateVector()
{
    vector<int> ins;//初始啥也没有
    srand((unsigned)time(NULL));
    for(int i = 0; i < 20; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    sort(ins.begin(), ins.end());
    return ins;
}

// 有序顺序表，去重
// 这个要是直接用STL的方法，一行代码unique即可
void uniqueVec(vector<int> &ins)
{
    auto it = unique(ins.begin(), ins.end()); // 返回的是指向重复的部分的开始
    // 释放重复元素的存储空间
    ins.erase(it,ins.end());
}

// 自己手写版本:非传引用调用
// 核心思想：因为有序，所以可以选择第一个出现的即可，后面的比较，如果已经存在则不要，否则就插入
vector<int> uniqueVecByHand(vector<int> ins)
{
    vector<int> res;
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        auto p = find(res.begin(), res.end(),*it); //看是否已经插入到res中了
        if(it != res.end())
        {
            res.push_back(*it);
        }
    }
    return res;
}
int main()
{
    //有序顺序表去重
    vector<int> ins = generateVector();
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    uniqueVec(ins); 
    vector<int> ins2 = uniqueVecByHand(ins);
    // 输出结果
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    for(auto it = ins2.begin(); it != ins2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
