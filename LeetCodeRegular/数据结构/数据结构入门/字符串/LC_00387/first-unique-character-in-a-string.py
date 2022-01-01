'''
387. 字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        position = dict() #创建字典
        n = len(s) 
        for i, ch in enumerate(s):
            if ch in position:
                position[ch] = -1
            else:
                position[ch] = i
        first = n
        for pos in position.values():
            if pos != -1 and pos < first:
                first = pos
        if first == n:
            first = -1
        return first
      
'''解题思路：
思路与算法

我们可以对方法一进行修改，使得第二次遍历的对象从字符串变为哈希映射。

具体地，对于哈希映射中的每一个键值对，键表示一个字符，值表示它的首次出现的索引（如果该字符只出现一次）或者 -1−1（如果该字符出现多次）。
当我们第一次遍历字符串时，设当前遍历到的字符为 cc，如果 cc 不在哈希映射中，我们就将 cc 与它的索引作为一个键值对加入哈希映射中，否则我们将 cc 在哈希映射中对应的值修改为 -1−1。

在第一次遍历结束后，我们只需要再遍历一次哈希映射中的所有值，找出其中不为 -1−1 的最小值，即为第一个不重复字符的索引。如果哈希映射中的所有值均为 -1−1，我们就返回 -1−1。
'''
