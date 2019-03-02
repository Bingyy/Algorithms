#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int low, int high) {
	// [low, high]
    int pivot = nums[low];

    while (low < high) {
        while (low < high && nums[high] >= pivot) {
        	high--;
        }
        nums[low] = nums[high];
        
        while (low < high && nums[low] <= pivot) {
        	low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low; // low == high
}

void quickSort(vector<int>& nums, int low, int high) {
	if (low > high) {
		return;
	}
	int index = partition(nums, low, high);
	quickSort(nums, low, index - 1);
	quickSort(nums, index + 1, high);
}

int main() {

	vector<int> nums; // = {1,2,3,5,4,6};
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);

	quickSort(nums, 0, nums.size() - 1);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	cout << endl;

    return 0;
}
