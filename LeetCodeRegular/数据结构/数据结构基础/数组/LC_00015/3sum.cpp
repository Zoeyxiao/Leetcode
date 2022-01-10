/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;       

        for(int i= 0; i < m ; i++){
            if(nums[0] > 0){
                return res;
            } //如果第一个数大于0，递增排序，后面的数就不用遍历了。
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }  // 去重：如果此数已经选取过，跳过
            int target = -nums[i];
            int left = i+1, right = m-1;
            while(left < right){
                if(nums[left] + nums[right] > target){
                    right--;
                }
                else if(nums[left] + nums[right] < target){
                    left++;
                }
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 去重：第二个数和第三个数也不重复选取
                    // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while(left<right && nums[left] == nums[left-1]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return res;
    }
};
