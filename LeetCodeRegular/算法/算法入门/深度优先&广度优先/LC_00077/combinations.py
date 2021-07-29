"""
77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
"""

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = [] #储存符合条件的结果集合
        path = [] #储存符合条件的结果
        def BackTrack(n, k, startIndex):
            if len(path) == k:
                res.append(path[:])
            for i in range(startIndex, n+1):
                path.append(i)
                BackTrack(n, k, i+1)
                path.pop()
        BackTrack(n,k,1)
        return res
