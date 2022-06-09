class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0; j<n; ++j){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                int d2 = 1e9,d3 = 1e9;
                int d1 = matrix[i][j] + dp[i-1][j];
                if(j>0){
                    d2 = matrix[i][j] + dp[i-1][j-1];
                }
                if(j<m-1){
                    d3 = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min({d1,d2,d3});
            }
        }
        int mini = 1e9;
        for(int j=0; j<n; ++j){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }
};