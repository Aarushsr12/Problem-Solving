class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i=1; i<n; ++i){
            int pick = nums[i] + ((i>1) ? dp[i-2] : 0);
            int nopick = 0 + dp[i-1];
            dp[i] = max(pick, nopick);            
        }
    return dp[n-1];
    }
};