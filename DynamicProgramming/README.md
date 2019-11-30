DP类型

一、线性DP

（状态表示是一个数组，即只存一种状态类型）
0053.MaximumSubarray.cpp (f[i]表示所有以i结尾的子段中的最大值)
0063.UniquePathsII.cpp
0072.EditDistance.cpp
0091.DecodeWays.cpp
0120.Triangle.cpp (f[i][j]表示从起点走到第i行第j个数的所有路径中的路径和最大值)

0300.LongestIncreasingSubsequence.cpp （线性DP+二分法）

（状态表示是两个数组，即有两种状态类型）
0198.HouseRobber.cpp (f[i]表示在前i个数中所有不选nums[i]的选法的最大值，g[i]表示在前i个数中所有选择nums[i]的选法的最大值)


二、区间DP

0664.StrangePrinter.cpp


三、背包问题

0518.CoinChange2.cpp
