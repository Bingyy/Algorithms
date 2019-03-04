#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
const int MAX = 100;
using namespace std;

// time : 2016-9-15 --中秋节
// author : Wang Bing

//抽出一个生成vector函数
vector<int> generateVector(int r)
{
    vector<int> ins;//初始啥也没有
    srand(r);
    for(int i = 0; i < 10; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    sort(ins.begin(), ins.end());//有序
    return ins;
}

// 升序序列的中位数：如果是4个数，则4/2 = 2，第二个数就是，如果5个数，则5/2 = 2.5,上取整3，第三个数就是
// 两个升序序列的中位数是包含所有元素的中位数

// 算法思想：模拟merge的过程，先根据总数确定中位数在素有元素中的位置，然后找一个指针在两个序列中游走即可

int getMidIndex(int a, int b)
{
    int t = a + b;
    if(t % 2 == 0)
    {
        return t / 2;
    }
    else
    {
        return t / 2 + 1;
    }
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
    vector<int> s1 = generateVector(1);
    vector<int> s2 = generateVector(3);

    int f1 = 0, f2 = 0; // 标记最后一棒在谁手中

    for(auto it = s1.begin();it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout  <<  endl;

    for(auto it = s2.begin();it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout  <<  endl;

    vector<int> res = mergeVec(s1,s2); //直接调用归并步骤不会错，但是空间复杂度和时间复杂度都较大

    //拿到位置，这里的位置是从1开始数的，因此索引的时候是索引都mid-1
    int mid = getMidIndex(s1.size(), s2.size());

    // auto pi = s1.begin(), pj = s2.begin();

    // int count = 1;
    //这一部分的逻辑么有走通
    // while(1){
    //     if(*pi >= *pj)
    //     {
    //         pj++;
    //         count++;
            
    //         if(count == mid)
    //         {
    //             f1 = 0;
    //             f2 = 1;
    //             break;
    //         }
    //     }
    //     if(*pj > *pi)
    //     {
    //         pi++;
    //         count++;
    //         if(count == mid)
    //         {
    //             f1 = 1; 
    //             f2 = 0;
    //             break;
    //         }
    //     }
    //     // count++;
    // }

    // if(f1 == 1)
    // {
    //     cout << *pi << endl; 
    // }
    // if(f2 == 1)
    // {
    //     cout << *pj << endl;
    // }

    cout << res[mid-1] << endl;
    return 0;
}
