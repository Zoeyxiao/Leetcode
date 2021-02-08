/*
978. 最长湍流子数组
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。
*/


//滑动窗口解法
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int length = 1;
        int left = 0, right = 0;
        while(right < n-1){
            if(left == right){
                if(arr[left] == arr[left+1]){
                    left++;
                }
                right++;
            }else{
                if(arr[right-1] < arr[right] && arr[right] > arr[right+1]){
                    right++;
                }else if(arr[right-1] > arr[right] && arr[right] < arr[right+1]){
                    right++;
                }else{
                    left = right;
                }
            }
            length  = max(length, right-left+1);            
        }
        return length;
    }
};

//DP解法
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                dp[i][0] = dp[i - 1][1] + 1;
            } else if (arr[i - 1] < arr[i]) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
        }

        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret = max(ret, dp[i][0]);
            ret = max(ret, dp[i][1]);
        }
        return ret;
    }
};
