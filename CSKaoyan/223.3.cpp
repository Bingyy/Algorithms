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

	// //数据清洗：去重
	// auto it = unique(ins.begin(), ins.end()); //返回的是重复部分的开始，所以删除时连同这个一起删掉
	// cout << "What is this : ";
	// cout << it-ins.begin() << endl;
	// ins.erase(it,ins.end());//删掉重复部分

	return ins;
}

void deleteElem(vector<int> & ins,int i) //删除下标为i的元素，所以i从0开始
{
	//从下标i+1开始到最后的元素全都往前挪，这里可以用一下erase删除末尾的空间
	for(auto it = ins.begin() + i; it != ins.end() - 1; it++)
	{
		*it = *(it + 1);
	}
	ins.erase(ins.end() - 1, ins.end()); //清除最后一个空间，可以改变end指针
}

int main()
{
	// 删除顺序表中所有值为x的元素
	//时间复杂度为O(n)，空间复杂度为O(1)

	vector<int> ins = generateVector();
	ins.push_back(ins[0]);
	ins.push_back(ins[0]);
	ins.push_back(ins[0]);

	for(auto it = ins.begin();  it != ins.end(); it++)
	{
		cout << *it << " "; 
	}
	cout << endl;

	int x;
	cin >> x;

	// 删除
	auto it  = find(ins.begin(),ins.end(),x);

	while(it != ins.end()) // it不为ins.end() 表示找到了
	{
		deleteElem(ins,it - ins.begin());
		it = find(ins.begin(),ins.end(),x);
	}

	for(auto it = ins.begin();  it != ins.end(); it++)
	{
		cout << *it << " "; 
	}
	cout << endl;

	return 0;
}