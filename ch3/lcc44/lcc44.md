# leetcode 44(通配符匹配)

__NOTES:__ 

+ isMatch_timeout: 这个函数的思路如下：

```
p[0] 为a到z的字符: return p[0] == s[0] && isMatch(s[1, end], p[1, end])
p[0] 为?: return isMatch(s[1, end], p[1, end])
p[0] 为*: 分三种情况
case 1: p[1, end] 为空
    return true;
case 2: p[1]为a到z的字符
    遍历s，如果 p[1] == s[i] && isMatch(s[i+1, end], p[2, end]) 为true，返回true，否则继续遍历s
case 3: p[1]为?
    遍历s, 如果 isMatch(s[i+1, end], p[2, end]) 为true，返回true, 否则继续遍历s

```

+ 但是上面的方法超时了(mmp), 用动态规划(代码见isMatch)来做这个题，可以通过，思路如下：

```
dp[j][i]: s[0,...,i]到p[0,...,j]的结果，递归式如下

如果 p[j] == '?'
dp[j][i] = dp[j-1][i-1]
如果 p[j] == 字母
dp[j][i] = p[j] == s[i] && dp[j-1][i-1]
如果 p[j] == '*'
dp[j][i] = dp[j][i-1] || dp[j-1][i] || dp[j-1][i-1]
```

+ 扫的规则为: "从小到大, 逐行扫描", 为了边界处理方便, 多加一行、一列, dp[0][0]为true, dp[0][i]为false, 其中i>0, 然后对于第一列的处理要注意边界情况 