class Solution {
public:
    int helper(vector<int> &sat,int index,int time,int n,vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        //pick or not pick
        int pick = sat[index] * time + helper(sat,index+1,time+1,n,dp);
        int notpick = helper(sat,index+1,time,n,dp);
        
        return dp[index][time] =  max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(),sat.end());
        
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return helper(sat,0,1,n,dp);
        
    }
};