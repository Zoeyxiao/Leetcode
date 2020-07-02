class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int n, int k) {
       int i = n - 1;
       int j = 0;
       int t = 0;
       while (i >= 0 && j < n){
           if(matrix[i][j] <= mid) {
               t += i+1;
               j++;
           }
           else{
               i--;
           }
       }
       return t >= k;       
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left < right){
            int mid = (left + right) / 2;
            if(check(matrix, mid, n, k)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

/*
首先需要注意的是题目给出的是特殊的矩阵类型，即从左上到右下是依序递增的矩阵（即matrix[0][0]是矩阵里的最小值，matrix[n-1][n-1]是矩阵里的最大值）
这里采用的是二分查找的方法：
首先先预设一个mid值，这里我取了最大值和最小值的平均值；
思路是：
若比mid小的数的数量不小于k，那么kth smallest number（x）就不小于mid；
若比mid小的数的数量小于k，那么kth smallet number(x) 就小于mid。

x >= mid && x < mid

*/
