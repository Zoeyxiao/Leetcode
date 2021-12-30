'''
118. 杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:

输入: numRows = 1
输出: [[1]]
'''

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        i,j = 0,0
        
        for i in range(1,numRows):
            t = [0 for _ in range(i+1)]
            t[0] = 1
            t[-1] = 1
            for j in range(1,i):                
                t[j] = ans[i-1][j-1]+ans[i-1][j]
                j += 1
            ans.append(t)
        return ans
      
      
#编程思路还是不成熟，循环设置总出问题，但是题目本身并不难。
