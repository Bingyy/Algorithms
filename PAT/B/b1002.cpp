/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100
​​
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
*/

#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> getDigits(int);

int main() {
  
  char str[101];
  // memset(str, 0, sizeof(str)); // 字符数组不能这么初始化
  map<int, string> mp;

  mp[0] = "ling";
  mp[1] = "yi";
  mp[2] = "er";
  mp[3] = "san";
  mp[4] = "si";
  mp[5] = "wu";
  mp[6] = "liu";
  mp[7] = "qi";
  mp[8] = "ba";
  mp[9] = "jiu";

  scanf("%s", str);

  int sum = 0;

  // 循环计算出数位之和
  for(int i = 0; str[i] != '\0'; i++) {
  	sum += (str[i] - '0');
  }

  // 将数字变成拼音
  vector<int> vec = getDigits(sum);
  for(auto it = vec.rbegin(); it != vec.rend(); it++) {
  	if(it != vec.rend() - 1) {
  		printf("%s ", mp[*it].c_str()); // c_str很重要
  	} else {
  		printf("%s\n", mp[*it].c_str()); // c_str很重要
  	}
  	
  }

  return 0;
}

vector<int> getDigits(int sum) {
	vector<int> vec;
	while(sum != 0) {
		int digit = sum % 10;
		vec.push_back(digit);
		sum /= 10;
  }
  return vec;
}

