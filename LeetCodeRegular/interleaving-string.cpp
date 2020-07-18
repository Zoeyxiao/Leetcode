class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size(), m = s2.size(), t = s3.size();
        
        if( t != n+m){
            return false;
        }

        vector<vector<int>>f(n+1, vector<int>(m+1, false));
        f[0][0] = true;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i > 0){
                    f[i][j] |= (f[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                if(j > 0){
                    f[i][j] |= (f[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
    return f[n][m];
    }
};

/*
不能采用双指针的方法，会有遗漏
用如上迭代方式才能比较全，但是我其实主要逻辑还是没理太清楚，只是惯性编程，还需要回头再理理思路
*/
