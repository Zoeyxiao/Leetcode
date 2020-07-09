class Trie{
public:
    Trie* next[26] = {nullptr};
    bool isEnd;

    Trie(){
        isEnd = false;
    }

    void insert(string s){
        Trie* curPos = this;

        for(int i = s.length()-1; i >= 0; --i){
            int t = s[i] - 'a';
            if(curPos -> next[t] == nullptr){
                curPos -> next[t] = new Trie();
            }
            curPos = curPos -> next[t];
        }
        curPos -> isEnd = true;
    }
};

//上面这个类是定义了字典（前缀）树

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f; 
        Trie* root = new Trie();
        for(auto& word: dictionary){
            root -> insert(word);
        }

        vector<int> dp(n+1, inf);
        dp[0] = 0;
         for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};


/*
0x3f3f3f3f的十进制是1061109567，是10^9级别的（和0x7fffffff一个数量级），而一般场合下的数据都是小于10^9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。
另一方面，由于一般的数据都不会大于10^9，所以当我们把无穷大加上一个数据时，它并不会溢出（这就满足了“无穷大加一个有穷的数依然是无穷大”），事实上0x3f3f3f3f+0x3f3f3f3f=2122219134，这非常大但却没有超过32-bit int的表示范围，所以0x3f3f3f3f还满足了我们“无穷大加无穷大还是无穷大”的需求。
*/
