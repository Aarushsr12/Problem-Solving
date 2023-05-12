class Solution {
public:
    
    long long maxPoints(int i, vector<vector<int>> &questions, int n, vector<long long> &dp){
        //base case
        if(i >=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        // long long num += questions[i][0] + maxPoints(i + questions[i][1], questions,n);
        long long res1 = questions[i][0] + maxPoints(i + questions[i][1] + 1,questions,n,dp);
        long long res2 = maxPoints(i+1, questions, n,dp);
        return dp[i] = max(res1, res2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
         int n = questions.size();
         //write a recursion first;
        vector<long long> dp(n,-1);
        return maxPoints(0,questions,n,dp);   
    }
};