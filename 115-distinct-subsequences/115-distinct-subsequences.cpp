class Solution {
public:
  int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j])
        {
            ans += solve(i+1,j+1,s,t,dp) + solve(i+1,j,s,t,dp);
        }
        else
        {
            ans += solve(i+1,j,s,t,dp);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = solve(0,0,s,t,dp);
        return ans;
    }
};