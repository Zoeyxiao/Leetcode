class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(), nums.end())){
            return true;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[i+1]){
                nums[i] = nums[i+1];
                if(is_sorted(nums.begin(), nums.end())){
                    return true;
                }
            }    
        }
    return false;
    }
};

//错了，但是还没想清楚错在哪里，不想学习的一天，明天再整理好了

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
                nums[i] = x; // 复原
                nums[i + 1] = x;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }
};
