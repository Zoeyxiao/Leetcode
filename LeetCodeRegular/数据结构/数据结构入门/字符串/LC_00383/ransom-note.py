'''
383. 赎金信
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
'''




class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m = len(ransomNote)
        n = len(magazine)

        dic = dict()
        word = dict()
        
        if m > n:
            return False

        for i, ch in enumerate(magazine):
            if ch in dic:
                dic[ch] = dic[ch] + 1
            else:
                dic[ch] = 1
        
        for j, ch1 in enumerate(ransomNote):
            if ch1 in word:
                word[ch1] = word[ch1] + 1
            else:
                word[ch1] = 1
        
        for j, ch1 in enumerate(ransomNote):
            if ch1 not in dic:
                return False
            elif ch1 in dic and word[ch1] <= dic[ch1]:
                j += 1
            else:
                return False
        return True
      
'''
题目要求使用字符串magazine 中的字符来构建新的字符串ransomNote，且ransomNote 中的每个字符只能使用一次，只需要满足字符串magazine 中的每个英文字母(’a’-’z’) 
的统计次数都大于等于ransomNote 中相同字母的统计次数即可。

如果字符串magazine 的长度小于字符串ransomNote 的长度，则我们可以肯定magazine 无法构成ransomNote，此时直接返回false。
首先统计magazine 中每个英文字母 a 的次数 cnt[a]，再遍历统计ransomNote 中每个英文字母的次数，如果发现ransomNote 中存在某个英文字母 c 的统计次数大于magazine 中该字母统计次数cnt[c]，
则此时我们直接返回false。

'''
