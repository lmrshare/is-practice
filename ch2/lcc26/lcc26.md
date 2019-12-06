# leetcode 26(删除排序数组中的重复项)

__NOTES:__ 用一个标记index代表已按照题意处理的数字, i从前往后扫描, 判断逻辑为

```
case: nums[i] != nums[index]
    index++
    nums[index] = nums[i]
case: nums[i] == nums[index]
    continue
```

+ 最后返回index+1即可