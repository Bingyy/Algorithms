#include <stdio.h>

int partition(int *a, int low, int high) {
	// [low, high]
	int pivot = a[low];

	while (low < high) {
		while (low < high && a[high] >= pivot) {
			high--; // pass the one greater pivot
		}

		// now a[high] < pivot
		a[low] = a[high];

		while (low < high && a[low] <= pivot) {
			low++; // pass the one less than pivot
		}
		a[high] = a[low];
		// if (low < high) {
		// 	swap(a[low], a[high]);
		// }
	}

	a[low] = pivot;

	return low;
}

void quickSort(int *a, int low, int high) {

	if (low > high) {
		return;
	}
	int index = partition(a, low, high);
	quickSort(a, low, index - 1);
	quickSort(a, index + 1, high);
}

// 快排 + 二分的思想
int getMedian(int *a, int size) {
	int low = 0, high = size - 1;
	int mid = (size - 1) / 2;
	int index = partition(a, low, high);

	while (mid != index) {
		// left half
		if (mid < index) {
			index = partition(a, low, index-1);
		} else {
			index = partition(a, index+1, high);
		}
	}
	return a[mid];
}

int main() {
	int a[5] = { 5,4,2,3,1 };

	// quickSort(a, 0, 4);

	// for (int i = 0; i < 5; i++) {
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	int median = getMedian(a, 5);
	printf("%d\n", median);
	return 0;
}