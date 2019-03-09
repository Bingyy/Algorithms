#include <stdio.h>


int main(int argc, char const *argv[])
{
	char str[100] = "123";
	int n;
	// string --> int
	sscanf(str, "%d", &n); // 从左到右
	printf("%d\n", n);

	// int --> string
	int m = 1234;
	char str2[100];
	sprintf(str, "%d", &m);
	printf("s", )
	return 0;
}