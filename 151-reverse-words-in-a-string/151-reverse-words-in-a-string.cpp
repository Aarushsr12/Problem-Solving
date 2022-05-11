class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string>st;
        int i=0;
        string ans="";
        for(int i=0; i<n; ++i){
            string str="";
            if(s[i] == ' '){
                continue;
            }
            while(i<n && s[i] != ' '){
                str += s[i];
                i++;
            }
            st.push(str);          
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};