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