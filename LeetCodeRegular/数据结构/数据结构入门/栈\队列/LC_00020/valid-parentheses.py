'''
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
'''

class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        if n % 2 == 1:
            return False

        #建立字典/哈希表
        dict = {")":"(", "]":"[", "}":"{"} 
        #Key为右括号

        #建立栈
        stack = list()

        for i in range(n):
            val = s[i]
            if val in dict:
                if not stack or stack[-1] != dict[val]: 
                    # stack[-1]在python中指的是列表中的最后一个元素
                    return False
                stack.pop()
            else:
                stack.append(val)
        
        return not stack
