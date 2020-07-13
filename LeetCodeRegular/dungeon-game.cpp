class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> HP(m+1, vector<int>(n+1, INT_MAX));
        int initHP = 0;
        //HP[m-1][n-1] = dungeon[m-1][n-1];
        HP[m][n-1] = HP[m-1][n] = 1; // 这里的初始化是本身这个值并不存在，因为要拯救到公主，那么这个值至少应该是1，所以初始化成这样。
        for (int i = m-1;i >= 0;i--){
            for (int j = n-1; j>= 0;j--){
                int minn = min(HP[i+1][j], HP[i][j+1]); //从右方和下方取最小值
                HP[i][j] = max(minn - dungeon[i][j], 1); // 因为可能出现负数或零的情况，这种时候即赋值为1；
            }
        }
        return HP[0][0];
    }
};

/*
有点类似上次的障碍路径数问题，不同的是如果从左上出发去右下，并不具备无后效性，即不是DP问题，但如果反过来，从右下到左上进行推导，那么就是典型的DP问题，转移状态如上
*/
