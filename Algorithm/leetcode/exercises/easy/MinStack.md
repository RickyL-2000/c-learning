# Min Stack

## My solution 1    2019/10/28

仔细思考之后发现，不能在结构体中申请数组。因为题目里貌似并没有限制栈高。所以得用结点的方式。


## My solution 2    2019/10/28

发现了神奇的函数 realloc() !!! 说不定可以适用数组方式实现了!!!