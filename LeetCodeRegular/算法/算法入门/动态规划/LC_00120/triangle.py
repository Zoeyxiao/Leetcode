"""
120. 三角形最小路径和
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

 

示例 1：

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
示例 2：

输入：triangle = [[-10]]
输出：-10
 

提示：

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
"""

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        """
        m = len(triangle)
        n = len(triangle[m-1])
        p = [0 for i in range(m)]
        j = 0
        p[0] = triangle[0][0]
        #print(p[0])
        for i in range(1, m):
            if triangle[i][j] < triangle[i][j+1]:
                p[i] = p[i-1] + triangle[i][j]
                j = j
            else:
                p[i] = p[i-1] + triangle[i][j+1]
                j = j+1
        return p[m-1] 
        以上为贪心算法，都为正数时可以，但是有负数的时候不行
        """
        
        m = len(triangle)
        n = m+1
        p = [[0 for i in range(m)] for j in range(n)]
        #j = 0
        p[0][0] = triangle[0][0]
        
        for i in range(1, m):
            p[i][0] = p[i-1][0] + triangle[i][0]
            for j in range(1, i):
                p[i][j] = min(p[i-1][j-1], p[i-1][j]) + triangle[i][j]           
            p[i][i] = p[i-1][i-1] + triangle[i][i]
            
                
        
        return min(p[m-1])

        




