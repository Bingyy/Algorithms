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
	for(int i = 0; i < 10; i++)//填充50个数据进来操作
	{
		int x = rand() % MAX;
		ins.push_back(x);
	}
	return ins;
}
// 基于erase版本，注意erase删除单个元素后迭代器的指向
void deleteElem(vector<int> &ins, int s,int t) //传递引用数据，直接操作源数据
{
	if(s > t)
	{
		cout << "Are you kidding?" <<endl;
	}
	//删除s和t之间的元素
	for(auto it = ins.begin();it != ins.end(); it++ )
	{
		if((*it >= s) && (*it <= t))
		{
			ins.erase(it); //删除单个迭代器指向的元素后，迭代器指针指向后面的元素，因此需要拉回来一步
			it--;
		}
	}
}

// 手工实现，基于算法的设计
// 核心思想是：从左往右遍历，
// 如果是应该删除的元素，那么计数一次，继续往前，
// 否则就把该元素的位置往前挪动k个
// 这个思想可以称作填坑，要删除一个就是一个坑，标记坑的数目，依次让不删除的元素跳过这些坑
void deleteElemByHand(vector<int> &ins, int s, int t)
{
	int k = 0;
	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		if(*it >= s && *it <= t)
		{
			k++;
		}
		else
		{
			*(it - k) = *it; 
		}
	}
	//清除最后k个元素的存储空间
	ins.erase(ins.end() - k, ins.end());
}

//从无序顺序表中删除其值在给定值s~t之间，包含s,t的所有元素，如果给出的区间不合理则显示出错信息并退出
//如果是基于简单的
int main()
{
	//基于vector实现的话这个算法很简单，调用erase即可
	vector<int> ins = generateVector();
	vector<int> ins2(ins.begin(), ins.end());
	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int s, t;
	cin >> s >> t;

	deleteElem(ins,s,t);
	deleteElemByHand(ins2,s,t);

	// 输出删除后结果
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
