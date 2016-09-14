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
	return ins;
}

//从有序顺序表中删除其值在给定值s~t之间，包含s,t的所有元素，如果给出的区间不合理则显示出错信息并退出

int main()
{
	vector<int> ins = generateVector();
	//序列排序
	sort(ins.begin(), ins.end());

	for(auto it = ins.begin(); it != ins.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	int s, t;
	cout << "Input the range [s , t] : ";
	while((cin >> s >> t) )
	{
		if(s > t)
		{
			cout << "Please input right range!" << endl;
			continue;
		}
		auto i = find(ins.begin(),ins.end(),s);
		auto j = find(ins.begin(),ins.end(),t);
		int ct = count(ins.begin(),ins.end(),t);
		j += ct;

		if(i == ins.end())
		{
			cout << s << " cannot be found!" << endl;
			continue;
		}
		if(j == ins.end())
		{
			cout << t << " cannot be found!" << endl;
			continue;
		}
		if(ins.empty())
		{
			cout << "Nothing to erase!" << endl;
		}
		if(i != ins.end() && j!= ins.end())
		{
			ins.erase(i,j); //删除的是包含i但是到j前面的那段数据
		}

		for(auto it = ins.begin(); it != ins.end(); it++)
		{
			cout << *it << " ";
		}
		
		cout << endl;
	}
	return 0;
}