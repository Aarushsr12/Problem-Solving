class Solution {
public:
    string greatestLetter(string s) {
        vector<int> low(26), Up(26);
        
        for(auto it: s){
            if(it-'A' >=0 && it-'A' <26){
                Up[it-'A']++;
            }
            else{
                low[it-'a']++;
            }
        }
        string res="";
        for(int i=25; i>=0; i--){
            if(low[i] && Up[i]){
                res = i+'A';
                break;
            }
        }
        return res;
    }
};