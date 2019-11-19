# 二分法

70%的二分题目都和单调性有关系
95%的二分题目都存在两段性的性质（在其中一段成立，在另一段不成立）

### 一、流程

1. 确定二分的边界：left、right
2. 编写二分的代码框架：两个模板（判断使用哪个模板）
3. 设计一个check：性质
    如果是等于(即大于等于、或者小于等于)的性质，则使用哪个模板都可以

### 二、模板

模板一

```
int binarySearch(int l, int r) {
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}
```

模板二

```
int binarySearch(int l, int r) {
    while (l < r) {
        int mid = l + ((long long)r - l + 1 >> 1);
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
```


### 三、题目

0033.SearchinRotatedSortedArray.cpp
0034.SearchforaRange.cpp
0035.SearchInsertPosition.cpp
0069.Sqrtx.cpp
0074.Searcha2DMatrix.cpp
0153.FindMinimuminRotatedSortedArray.cpp
0162.FindPeakElement.cpp
0275.H-IndexII.cpp
0278.FirstBadVersion.cpp
0287.FindtheDuplicateNumber.cpp
