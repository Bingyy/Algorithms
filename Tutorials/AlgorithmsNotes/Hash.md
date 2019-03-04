我们输入N个数，然后查询M个数是否在这N个数中出现过，构建一个布尔型数组，将输入的数作为数组的下标。

```cpp
#include <stdio.h>
const int maxn = 100010;

bool hashTable[maxn] = {false};

int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    hashTable[x] = true;
  }
  // check m numbers 
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    if (hashTable[x]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
```

如果需要统计出现的次数，将布尔型变成`int`型即可。

这是用空间换时间的策略。但是给出的案例是数字型的，输入的数据如果不是数据类型，该怎么办呢？能变成数据型吗？这就是**散列**的作用了。

散列的含义是：将元素通过一个函数转换为整数，并使得这个整数尽量能唯一代表这个元素。

#### 常见的散列方法

- 直接定址法：`H(key) = key`
- 平方取中法: 取key的平方的中间若干位作为hash值，不常用
- 除留余数法: `H(key) = key % mod`

#### 冲突的解决办法

- 线性探查法：当前的被占用，就查看下一个，到数组尽头就从头再来，有扎堆现象，即连续几个位置被占用
- 平方探查法：H(key) + 1^2, H(key) - 1^2, H(key)+2^2, H(key)-2^2,...
- 链地址法:将所有相同H(key)的key连接成一个单链表

这些原理可以掌握，在具体使用时，我们会用模板库，比如C++的map，在C++11后可以用`unordered_map`，这个速度更快。




