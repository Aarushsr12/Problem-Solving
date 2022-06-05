class Solution {
public:
    int helper(vector<vector<int>>& obs,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i >= 0 && j >= 0 && obs[i][j] == 1){
            return 0;
        }
        if(i == 0 && j == 0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = helper(obs,i-1,j,dp) + helper(obs,i,j-1,dp);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n = obs.size();
        int m = obs[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(obs,n-1,m-1,dp);
    }
};