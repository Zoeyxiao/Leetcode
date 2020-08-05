class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for(int i = 2; i <= n-1; i++){
            f[i] = max((f[i-2]+nums[i]), f[i-1]);
        }
        return f[n-1];   
    }
};

/*
以上为一般的DP解法，还可以用滚动数组法进行优化，如下代码所示
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for(int i = 2; i <= n-1; i++){
            int mid = f[1];
            f[1] = max((f[0]+nums[i]), f[1]); 
            f[0] = mid;
        }
        return f[1];   
    }
};


