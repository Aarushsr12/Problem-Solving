class Solution {
public:
    int evalRPN(vector<string>& s) {
        int cal;
        stack<int> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/"){
                st.push(stoi(s[i]));
            }
            else{
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                
                if(s[i] == "+"){
                    cal = op1 + op2;
                }
                else if(s[i] == "-"){
                    cal = op2 - op1;
                }
                else if(s[i] == "*"){
                    cal = op1 * op2;
                }
                else{
                    cal = op2/op1;
                }
                st.push(cal);
            } 
        }
        return st.top();
    }
};