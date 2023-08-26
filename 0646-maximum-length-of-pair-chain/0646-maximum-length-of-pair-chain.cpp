class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1] < v2[1];
    }
    int longestCount(int i,int prev,int n,vector<vector<int>> &pairs,vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int pick = 0;
        if(prev == -1 || pairs[prev][1] < pairs[i][0]){
            pick = 1 + longestCount(i+1,i,n,pairs,dp);    
        }
        int notpick = longestCount(i+1,prev,n,pairs,dp);
        return dp[i][prev+1] = max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int n = pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return longestCount(0,-1,n,pairs,dp);
    }
};