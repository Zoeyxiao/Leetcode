'''
566. 重塑矩阵
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。

给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。

如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

 
'''

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        if m * n != r * c:
            return mat
        
        i, j,x = 0, 0,0
        ans = [[0] * c for _ in range(r)]
        #num = m * n -1
        #for k in range(num):
        for i in range(m):
            for j in range(n):
                x = i * n + j
                i_1 = x//c
                j_1 = x%c
                ans[i_1][j_1] = mat[i][j]
        return ans
      
#解题的重点在于数学思维的转换，将原本问题转换为，原行列编号与新行列编号之间的数学关系问题，即得解此题。
