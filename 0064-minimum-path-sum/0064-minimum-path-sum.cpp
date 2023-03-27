class Solution {
public:
    int minPath(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i == 0 && j == 0){
         return grid[0][0];
        }
        if(dp[i][j] != 0) {
            return dp[i][j];
        }
        int sum1 = INT_MAX;
        int sum2 = INT_MAX;
        
        if(i > 0){
            sum1 = grid[i][j] + minPath(grid,i-1,j,dp);
        }
        if(j > 0){
            sum2 = grid[i][j] + minPath(grid,i,j-1,dp);
        }
        return dp[i][j] =  min(sum1, sum2);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        return minPath(grid,n-1,m-1,dp);
        
    }
};