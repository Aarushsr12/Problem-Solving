class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        for(int j=0; j<s.size(); ++j){
            if(s[j] == ' '){
                //s.begin()+j last white space will not be included in reverse
                reverse(s.begin()+i,s.begin()+j);
                i = j + 1;
            }
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};