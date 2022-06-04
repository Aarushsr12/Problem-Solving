class Solution {
public:
    int helper(int m,int n,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i>=m || j>= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = helper(m,n,i+1,j,dp) + helper(m,n,i,j+1,dp);
        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};