/*
1128. 等价多米诺骨牌对的数量
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> number(100,0);
        int count = 0;
        int n = dominoes.size();
        int m;
        for(int i = 0; i < n; i++){
            int x = dominoes[i][0];
            int y = dominoes[i][1];
            if(x <= y){
                count += number[x * 10 + y];
                number[x * 10 + y]++;
            }else{
                count += number[y * 10 + x ];
                number[y * 10 + x ]++;
            }
        }
        return count;

    }
};
