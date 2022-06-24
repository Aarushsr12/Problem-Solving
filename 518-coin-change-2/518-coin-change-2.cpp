class Solution {
public:
    int helper(int index,vector<int>& coins,int amount,int n,vector<vector<int>> &dp){
        //base case
        if(index == n){
            if(amount == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int take = 0;
        if(coins[index] <= amount){
            take = helper(index, coins,amount - coins[index],n,dp);
        }
        int notake = helper(index+1, coins,amount,n,dp);
        return dp[index][amount] = take + notake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return helper(0,coins,amount,n,dp);
    }
};