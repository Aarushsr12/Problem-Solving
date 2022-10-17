class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> m;
        int n = sentence.size();
        if(n < 26){
            return false;
        }
        else{
            for(int i=0; i<n; ++i){
                char s = sentence[i];
                m[s]++;
            }
            if(m.size() >= 26){
                return true;
            }
            else{
                return false;
            }
        }
    }
};