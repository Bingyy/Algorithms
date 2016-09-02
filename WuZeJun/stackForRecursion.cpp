#include<stack>
#include<cstdio>
using namespace std;

// 基于栈的递归调用
//以斐波那契为例
typedef struct Node{
	int n, tag;
}node;
int fib(int N)
{
	stack<node> s;
	node w;
	int sum = 0;
	do{
		while(N > 1)
		{
			w.n = N;
			w.tag = 1;
			s.push(w);
			N--;
		}
		//向左递归到底，边走边进栈
		sum = sum+N;
		while(!s.empty())
		{
			s.pop(w);
		}
}
	while();

}

int main()
{


}