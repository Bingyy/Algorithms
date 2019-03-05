
// P进制 --> 10进制
```cpp
int y = 0, product = 1;
while (x != 0) {
    y = y + (x % 10) * product;
    x = x / 10;
    product = product * P;
}

// return y
```