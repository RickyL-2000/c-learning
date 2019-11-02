# The implement of sqrt()

## my solution 1    2019/10/25  5 min

time: 40 ms     13.61%

memory: 6.9 mb  67.43%

```
int mySqrt(int x) {
    if (x == 0) return 0;
    long long i = 1;
    while (i*i <= x) {
        i++;
    }
    i--;
    return i;
}
```