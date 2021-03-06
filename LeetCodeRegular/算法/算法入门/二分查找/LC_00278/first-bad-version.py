
"""278. 第一个错误的版本
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

 
示例 1：

输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本"""

#https://leetcode-cn.com/submissions/detail/192659050/
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        res = right
        while left <= right:
            mid = (left+right)//2
            if isBadVersion(mid) == False:
                left = mid + 1
            elif isBadVersion(mid) == True:
                res = mid
                right = mid - 1
        return res    
       
class Solution:     
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 0, n+1
        while left < right:
            mid = (left + right) // 2
            if isBadVersion(mid) is False:
                left = mid + 1
                #mid = ((left + right) // 2)
            elif isBadVersion(mid) is True and isBadVersion(mid-1) is True:
                right = mid
            else:
                return mid
