class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int s1=INT_MAX,s2=INT_MAX;
        if(j>0){
            s1 = grid[i][j] + helper(grid,i,j-1,dp);
        }
        if(i>0){
           s2 = grid[i][j] + helper(grid,i-1,j,dp);
        }
        return dp[i][j] = min(s1,s2);
    }
    int minPathSum(vector<vector<int>>& grid){
      int n = grid.size();
      int m = grid[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
      return helper(grid,n-1,m-1,dp);  
    }
};