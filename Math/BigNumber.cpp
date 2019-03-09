#include <cstdio>
#include <string.h>

using namespace std;

// store the big number
struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
}; // 2345678, d[0] = 8, d[1] = 7,...

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0'; // reverse to get the digit
	}
	return a;
}

int compare(bign a, bign b) {
	if (a.len > b.len) {
		return 1; // a is greater
	}
	else if (a.len < b.len) {
		return -1;
	}
	else { // length is equal
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.d[i] > b.d[i]) {
				return 1;
			} else if(a.d[i] < b.d[i]) {
				return -1;
			}
		}
	}
	return 0;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b) {
	
}

int main() {

	char str1[1000], str2[1000];
	scanf("%s%s", str1, str2);
	bign a = change(str1);
	bign b = change(str2);

	bign addSum = add(a, b);

	print(addSum);
	printf("\n");

	return 0;
}