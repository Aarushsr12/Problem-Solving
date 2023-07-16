class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        int ans = 0;
        map<char,int> m;
        while(j < n){
            m[s[j]]++;
            while(m[s[j]] > 1){
                m[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};