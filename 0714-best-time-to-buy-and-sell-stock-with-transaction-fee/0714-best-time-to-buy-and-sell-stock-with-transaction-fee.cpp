class Solution {
public:
    int transcation(int index,int hold,vector<int>&prices,int fee,vector<vector<int>>&dp){
        //base case
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][hold] != -1){
            return dp[index][hold];
        }
        
        if(hold == 1){
            //we are buying
            int buy = transcation(index+1,0,prices,fee,dp) - prices[index] - fee;
            int notbuy = transcation(index+1,1,prices,fee,dp);
            
            dp[index][hold] =  max(buy, notbuy);
        }
        else{
            int sell = transcation(index+1,1,prices,fee,dp) + prices[index];
            int notsell = transcation(index+1,0,prices,fee,dp);
            dp[index][hold] = max(sell,notsell);
        }
        return dp[index][hold];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));    
        return transcation(0,1,prices,fee,dp);
        
    }
};