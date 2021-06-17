"""
65. 有效数字
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：

["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
部分无效数字列举如下：

["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
"""

class Solution:
    def isNumber(self, s: str) -> bool:
        # DFA transitions: dict[action] -> successor
        states = [
                  # initial state
                  {},
                  # state 1
                  {"blank":1,"sign":2,"digit":3,"dot":4},
                  # state 2
                  {"digit":3,"dot":4},
                  # state 3
                  {"digit":3,"dot":5,"e|E":6,"blank":9},
                  # state 4
                  {"digit":5},
                  # state 5
                  {"digit":5,"e|E":6,"blank":9},
                  # state 6
                  {"sign":7,"digit":8},
                  # state 7
                  {"digit":8},
                  # state 8
                  {"digit":8,"blank":9},
                  # state 9
                  {"blank":9}]

        def strToAction(st):
            if '0' <= st <= '9':
                return "digit"
            if st in "+-":
                return "sign"
            if st in "eE":
                return "e|E"
            if st == '.':
                return "dot"
            if st == ' ':
                return "blank"
            return None

        currState = 1
        for c in s:
            action = strToAction(c)
            if action not in states[currState]:
                return False
            currState = states[currState][action]

        # ending states: 3,5,8,9
        return currState in {3,5,8,9}


