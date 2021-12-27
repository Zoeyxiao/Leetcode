'''
53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0 for i in range(n)]
        f[0] = nums[0]       
        for i in range(1, n):
            f[i] = max(nums[i], f[i-1]+nums[i])
        ans = f[0]
        for i in range(n):
            ans = max(ans, f[i])    ###这一步是出错的一步，要注意返回的应该是所有求解的和中最大的，因此应该遍历之前所求的子数组和
        return ans    
