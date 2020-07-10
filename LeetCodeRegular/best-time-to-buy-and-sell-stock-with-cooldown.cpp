class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }

        int n = prices.size();
        vector<int> f(n), g(n), h(n);
        f[0] = -prices[0];
        for(int i = 1; i <= n-1; ++i){
            f[i] = max(f[i-1], h[i-1] - prices[i]);// 拥有一支股票的最大收益函数
            g[i] = f[i-1]+ prices[i]; // 不持有股票，且处于冻结状态的最大收益函数
            h[i] = max(g[i-1], h[i-1]); // 不持有股票，且不处于冻结状态的最大收益函数
        }
        return max(g[n-1], h[n-1]);
    }
};
/*
DP问题，关键在于找到状态转移关系，代码本身并没有难度。
我的代码还是略有冗余，完全可以只定义一个最大收益函数，也就是讲现在的一维向量，定义成2维即可。
*/
