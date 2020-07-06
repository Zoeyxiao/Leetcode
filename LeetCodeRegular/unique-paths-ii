class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<vector<int>> f(n, vector<int>(m,0));

        f[0][0] = (obstacleGrid[0][0] == 0); 

        for(int i = 0; i<=n-1; ++i){
            for(int j = 0; j<=m-1; ++j){
                if (obstacleGrid[i][j] == 1){
                    f[i][j] = 0;
                    continue;
                }
                if(i-1 >=0 && obstacleGrid[i-1][j] == 0){
                    f[i][j] += f[i-1][j];
                }
                if(j-1 >= 0 && obstacleGrid[i][j-1] == 0){
                    f[i][j] += f[i][j-1];
                    continue;
                }
            }  
        }
    return f[n-1][m-1];
    }
};

/*
以上为未用“滚动数组法”内存优化的版本， 题目重点在于要判断出这是一个动态优化的问题，例如本题中：
1. (i, j)(i,j) 位置只能从 (i - 1, j)(i−1,j) 和 (i, j - 1)(i,j−1) 走到，这样的条件就是「无后效性」。
2. 动态规划的题目分为两大类，一种是求最优解类，典型问题是背包问题，另一种就是计数类，比如这里的统计方案数的问题，它们都存在一定的递推性质。
   前者的递推性质还有一个名字，叫做 「最优子结构」 ——即当前问题的最优解取决于子问题的最优解，后者类似，当前问题的方案数取决于子问题的方案数。
   所以在遇到求方案数的问题时，我们可以往动态规划的方向考虑。（这里参考leetcode官方题解）
*/

**********************************************************************************************************************
//值得注意的是一般此类问题大多数都可以用“滚动数组思想”进行优化，即给空间复杂度降维，下面的代码版本为优化后的代码版本。
**********************************************************************************************************************

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);

        for(int i = 0; i<=n-1; ++i){
            for(int j = 0; j<=m-1; ++j){
                if (obstacleGrid[i][j] == 1){
                    f[j] = 0;
                    continue;
                }
                if(j-1 >= 0 && obstacleGrid[i][j-1] == 0){
                    f[j] += f[j-1];
                }
            }  
        }
    return f[m-1];
    }
};
    
    
