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

int main() {
	int a[5] = { 5,4,2,3,1 };

	quickSort(a, 0, 4);

	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}