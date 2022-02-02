class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n = s.size();
        int m = p.size();
        unordered_map<char,int> ms,mp;
        for(int i=0; i<m; ++i){
            mp[p[i]]++;
            ms[s[i]]++;
        }
        for(int i=m; i<n; ++i){
            if(ms == mp){
                ans.push_back(i-m);
            }
            //add character
            ms[s[i]]++;
            //remove the previous character
            ms[s[i-m]]--;
            if(ms[s[i-m]] == 0){
                ms.erase(s[i-m]);
            }
        }
        if(ms == mp){
            ans.push_back(n-m);
        }
        return ans;
    }
};