class Solution {
public:
    long long int mod = 1000000007; 
    long long int helper(int n,vector<long long int> &dp){
        //base case
        if(n == 1){
            dp[n] = 2;
        }
        if(n == 2){
            dp[n]= 3;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        long long int pick = helper(n-2, dp) % mod;
        long long int notpick = helper(n-1,dp) % mod;
        
        return dp[n] = (pick + notpick) % mod;
    }
    int countHousePlacements(int n) {
        vector<long long int> dp(n+1, -1);
        helper(n, dp);
        return (dp[n] * dp[n]) % mod;
    }
};