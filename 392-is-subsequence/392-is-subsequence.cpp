class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        
        string str="";
        while(i<s.size()  && j<t.size()){
            if(s[i] == t[j]){
               str += s[i]; 
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return (str == s);
    }
};