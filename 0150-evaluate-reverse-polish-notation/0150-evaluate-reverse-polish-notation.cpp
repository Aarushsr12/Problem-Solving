class Solution {
public:
    int evalRPN(vector<string> s) {
        //postfix notation
        long val = 0;
        stack<int> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/"){
                st.push(stoi(s[i]));
            }
            else{
                  long op1 = st.top();
                  st.pop();
                  long op2 = st.top();
                  st.pop();
                
                if(s[i] == "+"){
                    val = op1 + op2;
                }
                else if(s[i] == "-"){
                    val = op2 - op1; 
                }
                else if(s[i] == "*"){
                    val = op1 * op2; 
                }
                else{
                    val = (op2 / op1); 
                }
                st.push(val);
            }
        }
        return st.top();
    }
};