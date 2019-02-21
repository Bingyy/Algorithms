#include <cstdio>
#include <algorithm>

using namespace std;

/*
* 问题描述：第一层有1个数字，第二层有2个数字，...，第n层有n个数字，每次只能从当前向下走与之相连的两个数字
# 问：将路径上的数字相加最大是多少？
*/

const int maxn = 1000;
int n;

int f[maxn][maxn], dp[maxn][maxn]; // f数组记录每个节点的值，dp记录从该节点出发到叶子节点的最大值

// 核心思想：从最底层向上推导，因为子问题有重叠，需要用dp记录
// 递推公式：dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j]

int reverse_version(int x, int y) {

	// 递归基: 也是在最后一行时，注意下标是逐渐往下展开
	// 递归基不是只有1行，0行这种状况思考的，而是问题的初始值定义，因为只有一行也是从最后一行进行展开

	if (x == n) {
		dp[x][y] = f[x][y]; 

	} else {
		dp[x][y] = max(reverse_version(x+1, y), reverse_version(x+1, y+1)) + f[x][y];
	}

	return dp[x][y];
}

int iter_version() {

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
	return dp[0][0];
}
 
int main() {

	// 处理输入
	scanf("%d", &n); // 共n行
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}

	// 递推版本解决方案
	int iter_res = iter_version();
	int rev_res = reverse_version(0,0);

	printf("%d %d\n", iter_res, rev_res);

	return 0;

 }

