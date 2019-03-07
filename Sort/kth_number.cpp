#include <stdio.h>
#include <stdlib.h>

// Approach 1: Bubble Sort 
void bubbleSort(int *a, int n, int k) {
	// bubble sort: 递减排序
	for (int i = 0; i < n; i++) { // n轮次
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1] ) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

// Approach 2: Merge Sort, need to change the original array
// Descending sort
void merge(int *a, int low, int mid, int high) {
	// [low, mid)
	// [mid, high) 
	int *temp = (int *)malloc((high - low) * sizeof(int));
	int count = 0;

	int i = low, j = mid;

	while (i < mid && j < high) {
		if (a[i] > a[j]) {
			temp[count++] = a[i++];
		} else {
			temp[count++] = a[j++];
		}
	}

	while (i < mid) {
		temp[count++] = a[i++];
	}
	while (j < high) {
		temp[count++] = a[j++];
	}
	// dump the change to a
	count = 0;
	for (int i = low; i < high; i++) {
		a[i] = temp[count++];
	}
}

void mergeSort(int * a, int low, int high) {
	// base， it is very important
	if (high - low < 2) {
		return;
	}
	// int low = 0, high = n; 
	int mid = low + (high - low) / 2;

	mergeSort(a, low, mid); // check left and go back
	mergeSort(a, mid, high); // check right and go back
	merge(a, low, mid, high); // merge left and right
}

// Approach 3: Quick Sort
int partition(int *a, int low, int high) {
	// [low, high] is more convient
	int pivot = a[low];

	while (low < high) {
		while (low < high && a[high] <= pivot) {
			high--; // right to left to find the first number larger than pivot
		}

		a[low] = a[high];

		while (low < high && a[low] >= pivot) {
			low++;
		}

		a[high] = a[low];
	}

	a[low] = pivot;

	return low;
}

void quickSort(int *a, int low, int high) {
	// base is important
	if (low > high) {
		return;
	}

	int index = partition(a, low, high);
	quickSort(a, low, index - 1);
	quickSort(a, index + 1, high);

}

int getKthNumber(int *a, int n, int k) {
	// k: 1,2,3,...
	if (k > n - 1) {
		return -1;
	}
	return a[k-1];
}

// insert sort
int getKthNumber_m_2(int * a, int n, int k) {
	int *temp = (int *) malloc(k * sizeof(k));
	int i;
	temp[0] = a[0];
	int lastIndex = 0;
	// read the first k numbers and sort k numbers
	for (i = 1; i < k; i++) {
		while (a[i] > temp[lastIndex] && lastIndex >= 0) {
			int t = temp[lastIndex];
			temp[lastIndex] = a[i];
			a[i] = t;
			lastIndex--;
		}
		lastIndex = i - 1;
	}

	for (i = k; i < n; i++) {
		while (a[i] > temp[lastIndex] && lastIndex >= 0) {
			int t = temp[lastIndex];
			temp[lastIndex] = a[i];
			a[i] = t;
			lastIndex--;
		}
		lastIndex = k - 1;
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", temp[i]);
	}
	return temp[k-1];
}

// priority method

int main() {
	int a[] = {1, 3, 2, 5, 4};
	// bubble sort
	// printf("%d\n", res);
	
	// merge sort
	// mergeSort(a, 0, 5); // size
	// quickSort(a, 0, 4); // size - 1

	// int res = getKthNumber(a, 5, 1);
	// printf("%d\n", res);

	// for (int i = 0; i < 5; i++) {
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	int res = getKthNumber_m_2(a, 5, 5);
	printf("\n");
	printf("%d\n", res);



	return 0;
}