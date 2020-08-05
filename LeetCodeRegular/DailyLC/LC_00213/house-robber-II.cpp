class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        else if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> f(n);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for(int i = 2; i <= n-2; i++){
            f[i] = max((f[i-2]+nums[i]), f[i-1]);
        }
        vector<int> g(n);
        g[1] = nums[1];
        g[2] = max(nums[1], nums[2]);
        for(int j = 3; j <= n-1; j++){
            g[j] = max((g[j-2]+nums[j]), g[j-1]);
        }
        return max(f[n-2], g[n-1]);
    }
};

/*
和LC198打家劫舍的题类似，只不过多了一个条件是本题中的房间是换装排列的，所以难点在于怎么去分类讨论，也就是将这个环状排列问题优化为两个单排排列子问题，也就是两个
