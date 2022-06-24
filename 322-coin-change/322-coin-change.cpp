class Solution {
public:
    int helper(vector<int> &coins,int index,int amount,int n,vector<vector<int>> &dp){
        //base case 
        if(index == 0){
            if(amount % coins[index] == 0){
                return amount/coins[index];
            }
            else{
                return 1e9;
            }
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int take = 1e9;
        if(coins[index] <= amount){
            take = 1 + helper(coins,index, amount - coins[index],n,dp);
        }
        
        int notake = helper(coins,index-1, amount,n,dp);
        return dp[index][amount] = min(take, notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        //base case
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int res =  helper(coins,n-1,amount,n,dp);
        if(res == 1e9){
            return -1;
        }
        return res;
    }
};