#include <cstdio>
#include <algorithm>

using namespace std;

/*
* 问题描述：第一层有1个数字，第二层有2个数字，...，第n层有n个数字，每次只能从当前向下走与之相连的两个数字
# 问：将路径上的数字相加最大是多少？
*/

const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn]; // f数组记录每个节点的值，dp记录从该节点出发到叶子节点的最大值

// 核心思想：从最底层向上推导，因为子问题有重叠，需要用dp记录
// 递推公式：dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j]

int main() {
	int n;
	scanf("%d", &n); // 共n行
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}

	// 边界处理
	for (int j = 0; j < n; j++) {
		dp[n-1][j] = f[n-1][j]; // 最后的叶子节点值即为从此出发的最大值
	}

	// 自底向上递推
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
		}
	}

	printf("%d\n", dp[0][0]);

	return 0;

 }
