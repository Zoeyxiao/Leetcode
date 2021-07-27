"""
542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

 

示例 1：

输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]
示例 2：

输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]

https://leetcode-cn.com/problems/01-matrix/
"""

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        dis = [[0]*n for _ in range(m)]
        zero_pos = []
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    zero_pos.append((i,j))
        Q = collections.deque(zero_pos)
        Discoverd = set(zero_pos)

        while Q:
            i, j = Q.popleft()
            for s, t in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]:
                if 0 <= s <m and 0 <= t < n and (s,t) not in Discoverd:
                    dis[s][t] = dis[i][j] + 1
                    Q.append((s,t))
                    Discoverd.add((s,t)) 
        return dis
