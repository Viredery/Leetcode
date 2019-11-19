# LeetCode

通常，对于时间限制为1秒或者2秒的题目，C++可以执行的操作次数大概在10^7量级，不超过10^8

因此，在题目给出不同数据范围时，应选择不同时间复杂度的算法：

* n <= 20：O(2^n)、O(n!)等指数级别算法，DepthFirstSearch
* n <= 30：O(2^n)、O(n!)等指数级别算法，DepthFirstSearch+Pruning
* n <= 100：O(n^3)，图论中的Floyd、DynamicProgramming
* n <= 1000：O(n^2)或O(n^2 * logn)，DynamicProgramming、二分法
* n <= 10^5：O(n * logn)，各种排序、SegmentTree、树状数组、Set/Map（红黑树）、Heap、Dijkstra+Heap、SPFA、求凸包、求半平面交、二分法
* n <= 10^6：O(n)，Hash、TwoPointers、KMP、AC-Automation；常数比较小的O(n * logn)，排序、树状数组、Heap、Dijkstra、SPFA
* n <= 10^7：O(n)，TwoPointers、KMP、AC-Automation、线性筛素数
* n <= 10^18：O(logn)，数论题（最大公约数）


References
---
https://www.acwing.com
