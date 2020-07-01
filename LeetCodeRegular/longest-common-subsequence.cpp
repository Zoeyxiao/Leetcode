class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> C(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = 0; i <= n;i++){
            for (int j = 0; j <= m; j++){
                if(i == 0 || j== 0){
                    C[i][j] = 0;
                }
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
