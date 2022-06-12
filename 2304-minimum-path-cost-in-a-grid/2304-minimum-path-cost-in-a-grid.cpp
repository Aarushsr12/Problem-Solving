class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& moveCost,vector<vector<int>> &dp){
        //base case
        if(i == n-1){
            return grid[n-1][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=0; k<m; ++k){
            ans = min(ans,grid[i][j] + moveCost[grid[i][j]][k] + helper(grid,i+1,k,n,m,moveCost,dp));
        }
        return dp[i][j] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0; i<m; ++i){
            ans = min(ans,helper(grid,0,i,n,m,moveCost,dp));   
        }
        return ans;
    }
};