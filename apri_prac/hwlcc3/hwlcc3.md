# hwlcc3(无重复字符的最长子串)

__NOTES:__ 

+ s代表字符串, P[i]代表i打头的无重复字符最长子串的长度、S[i]代表无重复字符的最长子串的长度, 有如下递归式

```
P[i] = P[i-1] + 1; (if s[i] != s[i-1] != s[i-2]...s[0])
P[i] = 
```

__resource__

+ https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/