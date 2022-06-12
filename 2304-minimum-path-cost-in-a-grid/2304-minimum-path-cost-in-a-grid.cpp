class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mC) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0; j<m; ++j){
            dp[0][j] = grid[0][j];
        } 
        
        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                int ans = INT_MAX;
                for(int k=0; k<mC[grid[i][j]].size(); ++k){
                    ans = min(ans, grid[i][j] + mC[grid[i-1][k]][j] + dp[i-1][k]);
                }
                dp[i][j] = ans;
             }
        }
        int p =1e9;
        for(int i=0; i<m; ++i){
            p = min(p,dp[n-1][i]);
        }
        return p;   
    }
};