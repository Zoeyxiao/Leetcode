'''
217. 存在重复元素
给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
'''

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
      
#set()不允许存在重复元素，因此，若长度不一致返回true；反之，返回False;
#但上述代码不是这道题考察的数据结构，所以下面尝试从排序的角度重新编写代码；

