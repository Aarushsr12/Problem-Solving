class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        stack<string> st;
        string ans="";
        for(int i=0; i<n; ++i){
            string str="";
            if(s[i] =='/'){
                continue;
            }
            while(i<n && s[i] != '/'){
                str += s[i];
                i++;
            }
            if(str == "."){
                continue;
            }
            else if(str == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                cout<<str<<endl;
                st.push(str);
        
            }
        }
        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        if(ans.empty()){
            ans = '/';
        }
        return ans;
    }
};