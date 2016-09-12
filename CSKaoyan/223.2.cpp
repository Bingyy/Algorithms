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

	//数据清洗：去重
	auto it = unique(ins.begin(), ins.end()); //返回的是重复部分的开始，所以删除时连同这个一起删掉
	cout << "What is this : ";
	cout << it-ins.begin() << endl;
	ins.erase(it,ins.end());//删掉重复部分

	return ins;
}

//将顺序表元素逆置，空间复杂度为O(1)

void reverse_my_imple(vector<int> & ins) //传递引用，直接更改数据
{
	// reverse(ins.begin(), ins.end()); 
	//老老实实自己实现!
	//首尾交换是最快的方法
	for(auto s = ins.begin(),t = ins.end() - 1; s != t && s < t; s++, t--) //s不能跑到t右边去了，否则会内存溢出
	{
		*s ^= *t;
		*t ^= *s;
		*s ^= *t; // 比较酷炫的位运算式交换
		// int temp = *s;
		// *s = *t;
		// *t = temp; //常规交换
	}
}

int main()
{
	vector<int> ins = generateVector();
	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//逆置
	//但是这个reverse不是自己实现的
	// reverse(ins.begin(), ins.end());
	reverse_my_imple(ins);
	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}