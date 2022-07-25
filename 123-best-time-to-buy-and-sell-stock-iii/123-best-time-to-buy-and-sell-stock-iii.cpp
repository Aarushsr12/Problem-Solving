class Solution {
public:
    int helper(int index,int buy,int trans,vector<int>&prices,int n,vector<vector<vector<int>>> &dp){
        //base case
        if(index == n || trans == 0){
            return 0;
        }
        if(dp[index][buy][trans] != -1){
            return dp[index][buy][trans];
        }
        if(buy){
            dp[index][buy][trans] = max(-prices[index] + helper(index+1,0,trans,prices,n,dp), 0 +                                       helper(index+1,1,trans,prices,n,dp));
        }
        else{
            dp[index][buy][trans] = max(prices[index] + helper(index+1,1,trans-1,prices,n,dp), 0 +                                     helper(index+1,0,trans,prices,n,dp));        
        }
        return dp[index][buy][trans];
    }
    int maxProfit(vector<int>& prices) {
        //buy is a bool value 1 or 0
        int n = prices.size();
        //trans state will have 0/1/2
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return helper(0,1,2,prices,n,dp);
    }
};