"""
977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
"""

#解法一：直接排序
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []
        for i in range(n):
            res.append(pow(nums[i],2))
        res.sort()
        return res
       
#解法二：双指针，主要需要利用题目中数组是以非降序排列这一条件
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right = [], []
        res = []
        for i in range(n):
            if nums[i] > 0:
                right.append(pow(nums[i],2))
            else:
                left.append(pow(nums[i],2))
        m = len(right)
        k = len(left)
        if m == 0:
            return left[::-1]
        else:
            i = 0
            j = k-1
            while i < m  or j >= 0:
                if j < 0:
                    res.append(right[i])
                    i += 1
                elif i == m:
                    res.append(left[j])
                    j -= 1
                elif right[i] < left[j]:
                    res.append(right[i])
                    i += 1
                else:
                    res.append(left[j])
                    j -= 1
            return res
                

###代码还是不够简介，引入大量的中间list，代码还可以进一步优化

        
        
            
