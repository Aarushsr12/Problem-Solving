class Solution {
public:
    int numDecodings(string s) {
        //facebook level
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = (s[0]=='0')? 0:1;
        for(int i=2; i<=n; ++i){
            int k = 10*(s[i-2]-'0') + (s[i-1]-'0'); 
            if(s[i-1]-'0' >= 1){
                dp[i] += dp[i-1];
            }
            if(k>=10 && k<=26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};