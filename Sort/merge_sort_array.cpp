#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high) {
	// 合并需要对原数组带来实质性的变化
	vector<int> temp;

	int i = low, j = mid;

	while (i < mid && j < high) {
		if (nums[i] < nums[j]) {
			temp.push_back(nums[i++]);
		} else {
			temp.push_back(nums[j++]);
		}
	}
	// 还有未用完的
	while (i < mid) {
		temp.push_back(nums[i++]);
	}
	while (j < high) {
		temp.push_back(nums[j++]);
	}

	// 将数组复制到num中
	int count = 0;
	while (low < high) {
		nums[low++] = temp[count++];
	}
}

void mergeSort(vector<int> &nums, int low, int high) {
	// 只有一个元素时往回归
	if (high - low < 2) {
		return;
	}

	int mid = low + (high - low) / 2;
	mergeSort(nums, low, mid); // 左半边有序
	mergeSort(nums, mid, high); // 右半边有序
	merge(nums, low, mid, high); // 合并
 
}

int main() {
	vector<int> nums;
	int n, number;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		nums.push_back(number);
	}

	mergeSort(nums, 0, n);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}

	cout << endl;

	return 0;
}



