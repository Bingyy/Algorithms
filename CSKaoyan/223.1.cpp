//从顺序表中删除具有最小值的元素
//假设唯一
//返回删除的元素值
//空出的位置由最后一个元素填补
#include <iostream>
#include <vector>
#include <ctime>
const int MAX = 100;
using namespace std;

int main()
{
	vector<int> ins;//初始啥也没有
	srand((unsigned)time(NULL));
	for(int i = 0; i < 20; i++)//填充50个数据进来操作
	{
		int x = rand() % MAX;
		ins.push_back(x);
		// cout << x << " "; 
	}

	//数据清洗：去重
	auto it = unique(ins.begin(), ins.end()); //返回的是重复部分的开始，所以删除时连同这个一起删掉
	cout << "What is this : ";
	cout << it-ins.begin() << endl;
	ins.erase(it,ins.end());

	//输出顺序表的尺寸
	cout << "size: " << ins.size() << endl;

	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// 找到最小元素，并删除它，不动其他的结构
	int min = ins[0];
	for(auto it = ins.begin() + 1; it != ins.end(); it++)
	{
		if(min > *it)
		{
			min = *it;
		}
	}

	//不是调用vector自带的删除，而是自己模拟删除
	auto ptr = find(ins.begin(),ins.end(),min);
	// for(auto p = ptr; p != ins.end() - 1; p++)
	// {
	// 	*p = *(p + 1);
	// }

	//本例需要实现的是将删除元素的位置用最后一个元素填充：一行就可以
	*ptr = *(ins.end() - 1);

	cout << "size: " << ins.size() <<  endl;
	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}