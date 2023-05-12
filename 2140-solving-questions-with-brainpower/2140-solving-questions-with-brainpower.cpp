class Solution {
public:
    
    // long long maxPoints(int i, vector<vector<int>> &questions, int n, vector<long long> &dp){
    //     //base case
    //     if(i >=n){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     // long long num += questions[i][0] + maxPoints(i + questions[i][1], questions,n);
    //     long long res1 = questions[i][0] + maxPoints(i + questions[i][1] + 1,questions,n,dp);
    //     long long res2 = maxPoints(i+1, questions, n,dp);
    //     return dp[i] = max(res1, res2);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
         // now dp
        int n = questions.size();
        long long ans = INT_MIN;
        vector<long long> dp(n+1,0);
        dp[0] = questions[0][0];
        for(int i=n-1;  i>=0; --i){
            long long res = 0;
            if(i + questions[i][1] + 1 <= n){
                res = dp[i + questions[i][1] + 1];
            }
           dp[i] = max(res + questions[i][0], dp[i+1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};