#include <iostream>
#include <vector>
#include <ctime>
const int MAX = 100;
using namespace std;

//抽出一个生成vector函数：生成的数据不重复
vector<int> generateVector(int i)
{
    vector<int> ins;//初始啥也没有
    srand(i);
    for(int i = 0; i < 10; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    sort(ins.begin(), ins.end());
    return ins;
}

vector<int> mergeVec(vector<int> ins, vector<int> ins2)
{
    vector<int> res;
    
    auto i = ins.begin(),j = ins2.begin();
    
    while(i != ins.end() && j != ins2.end())
    {
        if(*i <= *j)
        {
            res.push_back(*i);
            i++; //你欺负我，我到后面找我哥哥，这句使得ins用完时迭代器指向的是尾后指针
        }
        if(*j < *i)
        {
            res.push_back(*j);
            j++; //我也到后面找我哥哥
        }
    }
    //谁哥哥多，接受最后的处理
    if(i != ins.end()) //若ins全都在前面，此时i指向的是尾后指针
    {
        for(auto it = i; it != ins.end(); it++)
        {
            res.push_back(*it);
        }
    }
    
    if(j != ins2.end())
    {
        for(auto it = j; it != ins2.end(); it++)
        {
            res.push_back(*it);
        }
    }
    
    return res;
}

int main()
{
    //将两个有序顺序表合成一个
    // 其实就是归并排序的最后的merge
    
    //首先生成两个有序的顺序表
    vector<int> ins = generateVector(1);
    vector<int> ins2 = generateVector(2);
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
    
    //处理
    ins = mergeVec(ins,ins2);
    
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
