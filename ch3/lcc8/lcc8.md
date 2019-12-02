# leetcode 8(字符串转换整数 (atoi))

__NOTES:__ 

+ 字符串处理，首先找到第一个非空字符，接着进行正负号判断，相应的把符号标记sign置起来，然后进行数字位的处理，处理算法如下：

```
val = val * 10 + str[i] - '0'
```

+ 边界处理为

```
case 1: val > INT_MAX/10
    越界
case 2: val == INT_MAX/10 && str[i] - '0' > INT_MAX%10
    越界
```