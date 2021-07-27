"""
994. 腐烂的橘子
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
"""

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        rot_pos = []
        fresh_cnt = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    rot_pos.append((i,j,0)) 
                if grid[i][j] == 1:
                    fresh_cnt += 1  #统计新鲜橘子的数量
        Q = collections.deque(rot_pos)
        
        d = 0
        while Q:
            i, j, d= Q.popleft()
            for s, t in [(i+1,j),(i,j+1),(i-1,j),(i, j-1)]:
                if 0 <= s < m and 0 <= t < n:
                    if grid[s][t] == 1:
                        grid[s][t] = 2
                        fresh_cnt -= 1
                        Q.append((s,t,d+1))
        
        if fresh_cnt == 0:
            return d
        else:
            return -1
