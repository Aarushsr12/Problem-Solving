class Solution {
public:
    char findTheDifference(string s, string t) {
       map<char,int>m;
        for(int i=0; i<s.size(); ++i){
            m[s[i]]++;
        }
        char ans;
        for(int i=0; i<t.size(); ++i){
            if(m[t[i]] > 0){
                //decrease the frequency
                m[t[i]]--;
            }
            else{
                ans=t[i];
            }
        }
        return ans;
    }
};