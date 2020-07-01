class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        //初始化二维数组
        vector<vector<int>> C(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = 0; i <= n;i++){
            for (int j = 0; j <= m; j++){
                if(i == 0 || j== 0){
                    C[i][j] = 0;
                }
                //这里之前出错是因为直接判定了A[i]==B[j],这样就跳过了A[0]和B[0],所以运行结果会出错
                else if(A[i-1] == B[j-1]){
                    C[i][j] = C[i-1][j-1]+1;
                    }
                    else{
                    C[i][j] = 0;
                    }
                res = max(res,C[i][j]);
                }
            } 
            return res;
        }
};

/*
要注意子序列是不连续的，子串/子数组是连续的
*/
