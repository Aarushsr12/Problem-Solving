class Solution {
public:
    bool canConstruct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        map<char,int> m2;
        for(int i=0; i<m; ++i){
            m2[s2[i]]++;
        }
        for(int i=0; i<n; ++i){
            if(m2[s1[i]] > 0){
                m2[s1[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};