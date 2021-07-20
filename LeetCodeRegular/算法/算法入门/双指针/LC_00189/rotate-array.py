"""
189. 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 

进阶：

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
 

提示：

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
"""
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i, j = 0, n-1
        k = k % n       ### mod很重要，不然如果k>n， 就会出现超出边界限制的问题
        while i < j :
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        m, h = 0, k-1
        while m < h:
            nums[m], nums[h] = nums[h], nums[m]
            m += 1
            h -= 1
        s, t = k, n-1
        while s < t:
            nums[s], nums[t] = nums[t], nums[s]
            s += 1
            t -= 1

            
###优化代码
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def swap(a, b):
            while a < b:
                nums[a], nums[b] = nums[b], nums[a]
                a += 1
                b -= 1

        n = len(nums)
        i, j = 0, n-1
        k = k % n
        swap(0, n-1)
        swap(0, k-1)
        swap(k, n-1)
