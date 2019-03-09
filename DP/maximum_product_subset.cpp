#include <iostream>
#include <vector>
#include <climits>

/*
* Time: 20190309
* BING W
* O(2^n)
*/

using namespace std;

void maxProduct(vector<int> const set, int &maximum)
{
	int product = 1;

	for (int j : set)
		product = product * j;

	// if the set is not empty, then update the product
	if (set.size() == 3) // here we can record 3 number's product, if not set we get the all subsets' product
		maximum = max (maximum, product);
}

// function to generate power set of a given set
// backtracking
void findPowerSet(vector<int> const &S, vector<int> &set, int n, int &maximum) {
	if (n == 0) {
		// all elements are used
		maxProduct(set, maximum);
		return ; // quit the current state
	}
	set.push_back(S[n-1]); // consider the nth element
	findPowerSet(S, set, n-1, maximum);

	// don't consider nth element
	set.pop_back();
	findPowerSet(S, set, n-1, maximum);
}

int main() {
	vector<int> S = {-6, 4, -5, 8, -10, 0, 8};
	int n = S.size();
	vector<int> set;
	int maximum = INT_MIN;

	findPowerSet(S, set, n, maximum);

	printf("The maximum product of a subset is %d\n", maximum );

	return 0;
}