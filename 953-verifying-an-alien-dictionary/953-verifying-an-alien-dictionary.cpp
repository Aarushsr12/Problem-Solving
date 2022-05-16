class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0; i<order.size(); ++i){
            m[order[i]] = i;
        }
        for(int i=0; i<words.size()-1; ++i){
            string s1 = words[i];
            string s2 = words[i+1];
            int i1=0, j=0;
            while(i1<s1.size() && j<s2.size() && s1[i1] == s2[j]){
                i1++;
                j++;
            }
            if(i1 < s1.size() && j == s2.size()){
                return false;
            }
            if(i1 < s1.size() && j < s2.size()){
                if(m[s1[i1]] > m[s2[j]]){
                    return false;
                }
            }
            
        }
        return true;
    }
};