###1190. 反转每对括号间的子串
###给出一个字符串 s（仅含有小写英文字母和括号）。

###请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

###注意，您的结果中 不应 包含任何括号。
###

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        for i in s:
            if i != ')':
                stack.append(i)
            elif i == ')':
                tmp = [];
                while stack and stack[-1] != '(':
                    tmp.append(stack.pop())
                stack.pop() #抛出左括号
                stack += tmp
        return "".join(stack)
