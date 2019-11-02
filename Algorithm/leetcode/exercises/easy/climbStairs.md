# Climbing Stairs

## my solution 1    2019/10/25  5 min

FAIL

because the time is run out, thanks to the recurse.

```
int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n-1) + climbStairs(n-2);
}
```

## my solution 2    2019/10/25  5 min

time: 4 ms  65.13%

memory: 6.9 mb  22.87%

```
int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    int result = 1/sqrt5*( pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+1));
    return result;
}
```