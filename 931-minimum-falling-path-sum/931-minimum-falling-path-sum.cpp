class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>&dp){
        //base case
        if(j<0 || j>n-1){
            return 1e9;
        }
        if(i == n-1){
            return matrix[n-1][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int d1 = matrix[i][j] + helper(matrix,i+1,j-1,n,dp);
        int d2 = matrix[i][j] + helper(matrix,i+1,j,n,dp);
        int d3 = matrix[i][j] + helper(matrix,i+1,j+1,n,dp);
        
        return dp[i][j] = min(d1,min(d2,d3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int k=0; k<m; ++k){
            ans = min(ans,helper(matrix,0,k,n,dp));
        }
        return ans;
    }
};