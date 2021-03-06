给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

 

示例：

输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int maxsum = sum;
        for(int i = k;  i < n; i++){
            sum = sum - nums[i- k] + nums[i];
            maxsum = max(maxsum,sum);
        }
        //double max = (double)maxsum;
        //double exp = max / k;
        return static_cast<double>(maxsum) / k;   //类里整型转浮点型的代码
        //return double(maxsum) / k;
       }
};
