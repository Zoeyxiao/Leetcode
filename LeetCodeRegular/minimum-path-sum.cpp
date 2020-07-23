class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>f(n+1, vector<int>(m+1, 0));
        f[0][0] = grid[0][0];
        for(int j = 1; j <= m-1; j++){
            f[0][j] += f[0][j-1] + grid[0][j];
        }
        for(int i = 1; i <= n-1; i++){
            f[i][0] += f[i-1][0] + grid[i][0];
        }
        
        for(int i = 1; i <= n-1; i++){
            for(int j = 1; j <= m-1; j++){
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        return f[n-1][m-1];
    }
};

/*
题目描述：
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小
*/

/*
解题思路：
典型的DP问题，所以应该是可以用窗口法优化的，回头有时间可以也写写
*/

