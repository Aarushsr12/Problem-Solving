class Solution {
public:
    int helper(int index,int n, vector<int> &cost,vector<int> &dp){
        //base case
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        return dp[index] = cost[index] + min(helper(index+1,n,cost,dp),helper(index+2,n,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(helper(0,n,cost,dp), helper(1,n,cost,dp));
    }
};