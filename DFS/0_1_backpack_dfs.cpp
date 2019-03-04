#include <cstdio>

const int maxn = 30;
int n, V, maxValue = 0;

/*
* time: 20190304, Mon
* 题目描述：n件物品，每件物品重量是w[i],价值是c[i]。选出若干件物品，存入容量为V的背包，
* 不超过V的情况下，最大化选择的物品价值
* 
* 思路：可以用DP来做，也可以用DFS来搜索
*/

int w[maxn], c[maxn]; 

// Time Complexicity: O(2^n)
void DFS(int index, int sumW, int sumC) {
	// 递归基，退出条件
	if (index == n) {
		if (sumW <= V && sumC > maxValue) {
			maxValue = sumC;
		}
		return ;
	}

	DFS(index + 1, sumW, sumC); // 不选择第index件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]);
}

// Faster
void DFS_2(int index, int sumW, int sumC) {
	if (index == n) {
		return;
	}
	DFS(index + 1, sumW, sumC);
	if (sumW + w[index] <= V) { // 加一些剪枝判断
		if (sumC + c[index] > maxValue) {
			maxValue = sumC + c[index];
		}
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}

int main() {
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w[i]); // 输入每件物品的重量
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]); // 每件物品的价值
	}

	DFS_2(0, 0, 0);
	printf("%d\n", maxValue);
	return 0;
}
