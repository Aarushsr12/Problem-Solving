class Solution {
public:
    char findTheDifference(string s, string t) {
        char x=0;
        for(int i=0; i<s.size(); ++i){
            x = x ^ s[i];
        }
        char y=0;
        for(int i=0; i<t.size(); ++i){
            y = y ^ t[i];
        }
        return x ^ y;
    }
};