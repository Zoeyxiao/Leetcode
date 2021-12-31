'''
73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
'''

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row, column = defaultdict(list), defaultdict(list)    
        m = len(matrix)
        n = len(matrix[0])

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i].append(i)
                    column[j].append(j)
        
        for i in range(m):
            if i in row:
                for j in range(n):
                    matrix[i][j] = 0
        
        for j in range(n):
            if j in column:
                for i in range(m):
                    matrix[i][j] = 0

        return matrix     
      
'''      
解题思路：
采用哈希表的方式，先进行一次遍历将矩阵中为零元素的行列编号记录下来；
然后进行二次遍历，将行列编号相同的元素都更新为零即可。
