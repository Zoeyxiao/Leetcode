编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1：

输入："hello"
输出："holle"
示例 2：

输入："leetcode"
输出："leotcede"

class Solution {
public:
    string reverseVowels(string s) {
        //if(s.empty() == true) return "False";
        string dict = "aeiouAEIOU";
        int i = 0, j= s.size() - 1;
        while(i < j){
            while(dict.find(s[i]) == dict.npos && i <  j)
            {
                i = i + 1;
            }
            while(dict.find(s[j]) == dict.npos && i < j)
            {
                j = j - 1;          
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

//算法不难，主要是对于函数不熟悉，这里用的函数主要是Find(), Swap(); 虽然用了不短的时间，不过没事，熟能生巧么
