#include <iostream>
#include <vector>
#include <ctime>
const int MAX = 100;
using namespace std;

//抽出一个生成vector函数
vector<int> generateVector(int i)
{
    vector<int> ins;//初始啥也没有
    srand(i);
    for(int i = 0; i < 20; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    // sort(ins.begin(), ins.end());
    return ins;
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

//主要分为三种情况：
// 1、m = n,直接顺序交换
// 2、m > n,先将b1,b1,...,bn与am-n,am-n+1,...,am交换，再将b1,b2,...,bn与a1,a2,...,an交换
// 3、m < n,先将a1,a2,...,am与b1,b2,...,bm交换，再将a1,a2,...,am与bm+1,bm+2,...,bn交换

void exchange(vector<int> &ins,int m, int n)
{
    if(m == n)
    {
        for(auto it = ins.begin(); it != ins.begin() + m; it++)//ins.begin()+m指向的是am后面的数字 
        {
            swap(*it,*(it+m));
        }
    }
    else if(m > n)
    {
        //前面的往后挪n位，后面的n位先保存再填充到前面n位

        //暂存
        vector<int> temp;
        for(auto it = ins.begin() + m; it != ins.end(); it++)
        {
            temp.push_back(*it);
        }

        // 往后移位，需要倒着想
        for(auto it = ins.rbegin() + n - 1; it != ins.rbegin() + n + m; it++)//ins.begin()+m指向的是am后面的数字 
        {
            *(it - n) = *it;
        }

        // 回填
        for(auto it = ins.begin(); it != ins.begin() + n; it++)
        {
            *it = temp[it-ins.begin()];
        }
    }
    else // m < n
    {
        //后面的往前挪m位，前面的m位先保存再填充到后面m位

        //暂存
        vector<int> temp;
        for(auto it = ins.begin(); it != ins.begin() + m; it++) //+m指向的是m+1位
        {
            temp.push_back(*it);
        }

        // 往前移位，需要倒着想
        for(auto it = ins.begin() + m; it != ins.end(); it++)//ins.begin()+m指向的是am后面的数字 
        {
            *(it - m) = *it;
        }

        // 回填最后的m位
        for(auto it = ins.begin() + n; it != ins.end(); it++)
        {
            *it = temp[it-ins.begin() - n];
        }
    }
}

//还有一种分治策略：首先将数组的全部元素原地逆置为：bn,bn-1,bn-2,...,b1,am,am-1,...,a1
//再对前n个元素和后m个元素分别使用逆置算法
//递归的思想

void reverse(vector<int> &ins, int m,int n)
{
    
}

int main()
{
    //一维数组中存放着两个线性表，a1,a2...,am,b1,b2,...bn
    //交换为 ：b1,b2,...bn,a1,a2...,am
    vector<int> ins = generateVector(1);
    int size = ins.size();
    cout << "Size is : " << size << endl;

    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    cout << "Enter m and n for m + n = size : ";
    int m,n;
    cin >> m >> n;
    if(m + n != size)
    {
        cout << "Are you kidding? Please do right math!" << endl;
    }

    //处理

    exchange(ins,m,n);

    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
