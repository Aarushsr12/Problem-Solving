class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        string ans="";
        while(i < n){
            string temp = "";
            if(s[i] == ' '){
                //ignore spaces
                i++;
            }
            while(i<n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp.empty() == false){
                ans = temp + " " + ans;
            } 
        }
        ans.pop_back();
        return ans;
    }
};