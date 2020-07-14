class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> F(m, vector<int>(m));
        F[0][0] = triangle[0][0];

        for(int i = 1; i <= m-1; i++){

            F[i][0] = F[i-1][0]+triangle[i][0];

            for(int j = 1; j < i; j++){
                F[i][j] = min(F[i-1][j-1], F[i-1][j]) + triangle[i][j];
            }   
            F[i][i] = F[i-1][i-1] + triangle[i][i];
        }
        return *min_element(F[m - 1].begin(), F[m - 1].end());
    }
};

