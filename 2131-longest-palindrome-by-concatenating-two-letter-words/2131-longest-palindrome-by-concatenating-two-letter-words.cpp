class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int res =0;
        for(int i=0; i<words.size(); ++i){
            string str = words[i];
            reverse(str.begin(),str.end());
            if(m[str] > 0){
                res += 4;
                m[str]--;
            }
            else{
                m[words[i]]++;
            }
        }
        
        for(auto it : m){
            if(it.first[0] == it.first[1] && it.second > 0){
                return res + 2;
              }
        }
        return res;
    }
};