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
    for(int i = 0; i < 10; i++)//填充50个数据进来操作
    {
        int x = rand() % MAX;
        ins.push_back(x);
    }
    sort(ins.begin(), ins.end());//有序
    return ins;
}

//返回找到的下标或者找不到返回-1
int bisearch(vector<int> ins, int x)
{
    int left = 0, right = (int)ins.size() - 1;
    int mid = (left + right) / 2;
    
    while(left <= right ) //注意包含等于号，否则最后一个无法到达
    {
        if(x == ins[mid])
        {
            return mid;
        }
        if( x < ins[mid])
        {
            right = mid - 1; //右边赋值mid即可，若是mid-1，则会漏过一些数
        }
        if(x > ins[mid])
        {
            left = mid + 1;
        }
        mid = (right + left) / 2;
    }
    return -1;
}



int main()
{
    // 递增有序的线性表，在最少时间内查找数值为x的元素，
    // 如果找到就将其与后继元素的位置相交换，
    // 找不到就插入表中，使得表仍然递增有序
    
    vector<int> ins = generateVector(3);
    
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    
    //处理
    
    cout << "Input a number: ";
    int x;
    cin >> x;
    
    //二分查找 : 返回下标
    
    int index = bisearch(ins,x);
    
    cout << "index is: " << index << endl;
    
    if(index != -1)
    {
        // swap(ins[index],ins[index+1]);
        ins[index] ^= ins[index + 1];
        ins[index + 1] ^= ins[index];
        ins[index] ^= ins[index + 1];
    }
    
    if(index == -1) //找不到啊，就加进来,这个可以手工实现
    {
        // ins.push_back(x);
        // sort(ins.begin(),ins.end());//这是很懒的做法~
        // 手工实现必然是O(n)的时间效率
        // 首先找到第一个比x小的元素，返回下标
        // 后面全部往后挪一个位置
        ins.push_back(-1); //插入一个哨兵，扩大容器容量
        int i = (int)ins.size() - 2;
        
        for(; i > 0; i--)
        {
            if(ins[i] < x)//这个控制很重要
            {
                ins[i+1] = x;
                break;
            }
            
            if(ins[i] > x)
            {
                ins[i+1] = ins[i];//后挪一位
                ins[i] = x;
            }
            if(ins[i] < x)
            {
                break;
            }
        }
        
    }
    
    
    for(auto it = ins.begin(); it != ins.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
    printf("%x\n", 273);
    
    return 0;
}
